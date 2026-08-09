/*
main 문을 읽고 해석하여 LOSS 를 최소화해라
*/

/*
Step.0
Get User and NetworkBase

Step.1 그리드(격자모양)하게 이동하면서 유저를 그리디하게 가장 가까운 기지국에 할당.

Step.2 기지국이 꽉차면 근처 기지국으로 할당.

Step.3
유저 끼리 Swap 해보면서 최소화. (A, B), (A, B, C)

Step.Last
Set User alloc NetworkBase
*/

#define CSIZE 5000
#define CELLBASE_CNT 4
#define USER_CNT 250000

#define MAX_NB 67500
#define MAX_D 50'000'000

char (*cell)[CSIZE];
int userY[USER_CNT];
int userX[USER_CNT];
int userN[USER_CNT];
int userABCD[USER_CNT][CELLBASE_CNT + 1];
int userDD[USER_CNT][CELLBASE_CNT + 1];

// 0번 기지국은 안씀.
int ncY[CELLBASE_CNT + 1];
int ncX[CELLBASE_CNT + 1];
int nbSize[CELLBASE_CNT + 1];
int nbUsers[CELLBASE_CNT + 1][MAX_NB];

inline void sortNB(int n, int y, int x) {
    int dd[CELLBASE_CNT + 1];
    for (int i = 1; i < 5; ++i) {
        int yy = ncY[i] - y;
        int xx = ncX[i] - x;
        dd[i] = yy * yy + xx * xx;
        userDD[n][i] = dd[i];
    }
    // naive sort
    for (int i = 1; i < 5; ++i) {
        int tmp = MAX_D;
        int target = -1;
        for (int j = 1; j < 5; ++j) {
            if (tmp > dd[j]) {
                tmp = dd[j];
                target = j;
            }
        }
        dd[target] = MAX_D;
        userABCD[n][i] = target;
    }
}

int userNum[MAX_NB * 2];
int userV[MAX_NB * 2];

void mergeSort(int left, int right);
void sortAB(int a, int b) {
    int cnt = 0;
    int userNumber = -1;
    for (int i = 0; i < nbSize[a]; ++i) {
        userNumber = nbUsers[a][i];
        userNum[cnt] = userNumber;
        userV[cnt] = userDD[userNumber][a] - userDD[userNumber][b];
        ++cnt;
    }
    for (int i = 0; i < nbSize[b]; ++i) {
        userNumber = nbUsers[b][i];
        userNum[cnt] = userNumber;
        userV[cnt] = userDD[userNumber][a] - userDD[userNumber][b];
        ++cnt;
    }
    mergeSort(0, cnt - 1);
}

int mergeCopy1[MAX_NB * 2];
int mergeCopy2[MAX_NB * 2];
void mergeSort(int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    for (int i = left; i <= right; ++i) {
        mergeCopy1[i] = userV[i];
        mergeCopy2[i] = userNum[i];
    }

    int cnt = left;
    int idx1 = left;
    int idx2 = mid + 1;
    while (cnt <= right) {
        if (idx1 == mid + 1) { // right copy
            while (idx2 < right + 1) {
                userV[cnt] = mergeCopy1[idx2];
                userNum[cnt] = mergeCopy2[idx2];
                ++idx2;
                ++cnt;
            }
            break;
        }
        else if (idx2 == right + 1) { // left copy
            while (idx1 < mid + 1) {
                userV[cnt] = mergeCopy1[idx1];
                userNum[cnt] = mergeCopy2[idx1];
                ++idx1;
                ++cnt;
            }
            break;
        }

        if (mergeCopy1[idx1] <= mergeCopy1[idx2]) { // left copy
            userV[cnt] = mergeCopy1[idx1];
            userNum[cnt] = mergeCopy2[idx1];
            ++idx1;
            ++cnt;
        }
        else { // right copy
            userV[cnt] = mergeCopy1[idx2];
            userNum[cnt] = mergeCopy2[idx2];
            ++idx2;
            ++cnt;
        }
    }
    return;
}

void test(void* param)
{
    // Step.0
    // Get User and NetworkBase, init
    for (int i = 1; i < 5; ++i)
        nbSize[i] = 0;
    cell = (char(*)[CSIZE])param;
    int userCnt = 0;

    for (int i = 0; i < CSIZE; ++i) {
        for (int j = 0; j < CSIZE; ++j) {
            if (cell[i][j] < 0) {
                ncY[-cell[i][j]] = i;
                ncX[-cell[i][j]] = j;
            }
            else if (cell[i][j] > 0) {
                userY[userCnt] = i;
                userX[userCnt] = j;
                ++userCnt;
            }
        }
    }

    // step.1
    for (int i = 0; i < USER_CNT; ++i) {
        sortNB(i, userY[i], userX[i]);
        // step.2
        for (int j = 1; j < 5; ++j) {
            int target = userABCD[i][j];
            if (nbSize[target] < MAX_NB) {
                userN[i] = target;
                nbUsers[target][nbSize[target]] = i;
                ++nbSize[target];
                break;
            }
        }
    }

    // step.3
    for (int round = 0; round < 8; ++round) {
        for (int nba = 1; nba < 5; ++nba) {
            for (int nbb = nba + 1; nbb < 5; ++nbb) {
                // AB 셀에 연결된 유저 정렬
                sortAB(nba, nbb);
                int n = nbSize[nba] + nbSize[nbb];
                // t = v가 음수인 개수
                int t = 0;
                while (t < n && userV[t] < 0) ++t;
                // 정원으로 clamp
                if (t > MAX_NB)     t = MAX_NB;
                if (n - t > MAX_NB) t = n - MAX_NB;

                int idx1 = 0;
                int idx2 = 0;
                for (int i = 0; i < n; ++i) {
                    // A 할당
                    if (i < t) {
                        nbUsers[nba][idx1] = userNum[i];
                        userN[userNum[i]] = nba;
                        ++idx1;
                    }
                    // B 할당
                    else {
                        nbUsers[nbb][idx2] = userNum[i];
                        userN[userNum[i]] = nbb;
                        ++idx2;
                    }
                }
                // resize
                nbSize[nba] = t;
                nbSize[nbb] = n - t;
            }
        }
    }

    // Step.Last
    // Set User alloc NetworkBase
    for (int i = 0; i < USER_CNT; ++i) {
        int y = userY[i];
        int x = userX[i];
        cell[y][x] = userN[i];
    }
}
