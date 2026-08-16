
// ── 측정으로 확정한 것 ────────────────────────────────────────────────
//   하한 1503 : 용량을 무시하고 각 집을 가장 가까운 쉘터에 붙였을 때의 점수.
//   천장 1668 : 연속 구간 3분할(경계 2개)을 완전탐색했을 때의 최선.
//               기준선 1640 을 못 넘는다  =>  답은 구간 분할이 아니다.
//   채점기는 비용을 "집 단위" 로 더하고, 용량은 "사람 단위" 로 센다.
//               =>  같은 거리 손해라면 인원이 많은 집을 옮기는 쪽이 자리를 더 많이 비운다.
//               =>  옮길 우선순위 = (늘어나는 거리) / (그 집의 인원), 작은 것부터.
//
// ── 알고리즘 ─────────────────────────────────────────────────────────
//   1) 각 집을 가장 가까운 쉘터에 배정한다.
//   2) A 와 C 의 초과분을 B 로 옮긴다. 이때 B 가 용량을 넘어도 무시한다.
//   3) B 의 초과분을 A / C 중 그 집에게 싼 쪽으로 옮긴다.
//      자리가 항상 충분한 근거:
//        필요한 자리 = (총합 - A' - C') - CAP
//        있는 자리   = (CAP - A') + (CAP - C')
//        차이        = 3*CAP - 총합 = 60000 - 약 50000 > 0
//      (총합은 집 10000 채 x 평균 5 명 = 약 50000. 표준편차가 258 이라 60000 은 38 시그마.)
//
// ── 후보를 고르는 방법: "경계에서 바깥으로 걸으며 인원별 통에 던진다" ──
//   층이 10000 개라 층마다 정렬을 돌리면 시간이 안 나온다. 그런데 정렬이 애초에 필요 없다.
//
//   (1) 경계에서 멀어질수록 옮기는 손해가 커진다.
//       => 경계에서 바깥으로 걸어나가는 순서가 곧 "손해 오름차순" 이다.
//          A 의 경계는 목록 끝쪽,  C 의 경계는 목록 앞쪽,  B 는 양쪽 끝이 다 경계다.
//          (그래서 collectCandidates 가 커서를 left, right 두 개 들고 있다.
//           A/C 에서는 한쪽만 움직이고, B 에서만 양쪽이 번갈아 움직인다.)
//   (2) 인원은 1~9 뿐이다. 걸어나가면서 인원별 9 개 통에 던져 넣으면,
//       던지는 순서가 이미 손해 오름차순이므로 각 통이 저절로 정렬된다.
//       같은 인원끼리는 손해 순서 = 비율 순서이기 때문이다.
//   (3) 꺼낼 때는 통 9 개의 뚜껑만 본다. 각 통이 정렬돼 있으니 전체 최소는 그 안에 있다.
//
//   나눗셈은 정수에서 버려지므로 비율 비교는 교차 곱셈으로 한다.
//
//   참고 실측: 최근접 배정만 하고 용량 처리를 통째로 빼도 2.94s 다 (배열이 10000x10000).
//   즉 이 알고리즘 전체가 0.03s 이고, 시간의 대부분은 입력 크기 자체에서 나온다.
//   정렬로 바꾸면 5.34s 가 되는데, 그건 정렬이 느려서지 알고리즘이 무거워서가 아니다.

const int FLOOR = 10000;
const int LINE  = 10000;   // 한 층의 칸 수
const int CAP   = 20000;   // 쉘터 1 개의 수용 인원

// ── 칸(집) 별 정보 ──
static int peopleAt[LINE];     // 그 칸에 사는 인원. 쉘터 칸은 0
static int assignedTo[LINE];   // 그 집이 현재 배정된 쉘터 (0=A, 1=B, 2=C)
static int moveCost[LINE];     // 이번 단계에서 옮길 때 늘어나는 거리
static int moveTo[LINE];       // 이번 단계에서 옮길 목적지 쉘터 (3 단계 전용)

// ── 쉘터별 정보 ──
// shelterHouse[k] 에는 k 번 쉘터가 담당하는 집들의 칸 인덱스가 들어간다.
// 항상 칸 인덱스 오름차순이어야 한다 — collectCandidates 의 전제.
static int shelterHouse[3][LINE];
static int shelterHouseCnt[3];   // shelterHouse[k] 에 들어있는 집의 개수
static int shelterPeople[3];     // k 번 쉘터에 배정된 총 인원

// ── 인원(1~9) 별 후보 통 ──
// candBox[n] 에는 인원이 n 명인 후보 집들이 "손해 오름차순" 으로 들어간다.
static int candBox[10][LINE];
static int candBoxCnt[10];       // candBox[n] 에 담은 개수
static int candBoxTaken[10];     // candBox[n] 에서 꺼내간 개수 (앞에서부터 꺼낸다)

static inline int absInt(int v) { return v < 0 ? -v : v; }

// 경계에서 바깥으로 걸어나가면서 후보를 인원별 통에 던져 담는다.
// 양 끝 중 손해가 작은 쪽을 집으면 그게 곧 "경계에서 바깥으로" 다.
//
// needPeople: 통에 모아야 할 인원. 이만큼 모이면 뒤는 볼 필요가 없다.
//   손해 오름차순으로 담으므로, 잘려나간 집들은 전부 담은 집들보다 손해가 크다.
//   초과분만큼만 모아두면 그 안에서 반드시 해소되므로 정답성은 유지된다.
//   목록 전체를 훑으면 층당 1 만 회인데, 실제로 옮기는 집은 그 일부뿐이다.
static void collectCandidates(const int* houseList, int count, int needPeople)
{
    for (int n = 1; n <= 9; ++n) { candBoxCnt[n] = 0; candBoxTaken[n] = 0; }

    int left = 0, right = count - 1, gathered = 0;
    while (left <= right && gathered < needPeople) {
        int houseIdx;
        if (moveCost[houseList[left]] <= moveCost[houseList[right]])
            houseIdx = houseList[left++];
        else
            houseIdx = houseList[right--];

        int n = peopleAt[houseIdx];
        candBox[n][candBoxCnt[n]++] = houseIdx;
        gathered += n;
    }
}

// 통 9 개의 뚜껑(맨 앞 후보) 중 (늘어나는 거리)/(인원) 이 가장 작은 통의 번호를 돌려준다.
// 통 번호가 곧 그 통에 든 집들의 인원이다. 남은 후보가 하나도 없으면 0.
static int pickCheapestBox()
{
    int bestBox = 0;
    for (int n = 1; n <= 9; ++n) {
        if (candBoxTaken[n] >= candBoxCnt[n]) continue;   // 이 통은 비었다
        if (bestBox == 0) { bestBox = n; continue; }

        int costHere = moveCost[candBox[n][candBoxTaken[n]]];
        int costBest = moveCost[candBox[bestBox][candBoxTaken[bestBox]]];
        // costHere/n < costBest/bestBox  <=>  costHere*bestBox < costBest*n
        // (n 과 bestBox 가 양수라 부등호 방향이 보존된다)
        if (costHere * bestBox < costBest * n) bestBox = n;
    }
    return bestBox;
}

void assign(int house[FLOOR][10000])
{
    for (int floor = 0; floor < FLOOR; ++floor) {

        // 쉘터 위치. 앞에서부터 훑으므로 shelterPos[] 는 자동으로 오름차순이다.
        int shelterPos[3];
        int found = 0;
        for (int i = 0; i < LINE; ++i) {
            peopleAt[i] = house[floor][i];
            if (peopleAt[i] == 0) shelterPos[found++] = i;
        }

        // ── 1) 최근접 배정 ──
        shelterHouseCnt[0] = shelterHouseCnt[1] = shelterHouseCnt[2] = 0;
        shelterPeople[0]   = shelterPeople[1]   = shelterPeople[2]   = 0;

        for (int i = 0; i < LINE; ++i) {
            if (peopleAt[i] == 0) continue;

            int distA = absInt(shelterPos[0] - i);
            int distB = absInt(shelterPos[1] - i);
            int distC = absInt(shelterPos[2] - i);

            int nearest = (distA <= distB) ? 0 : 1;
            if (distC < ((nearest == 0) ? distA : distB)) nearest = 2;

            assignedTo[i] = nearest;
            shelterHouse[nearest][shelterHouseCnt[nearest]++] = i;
            shelterPeople[nearest] += peopleAt[i];
        }

        // ── 2) A 와 C 의 초과분을 B 로 (B 가 넘쳐도 무시) ──
        for (int step = 0; step < 2; ++step) {
            int from = (step == 0) ? 0 : 2;
            if (shelterPeople[from] <= CAP) continue;

            for (int j = 0; j < shelterHouseCnt[from]; ++j) {
                int houseIdx = shelterHouse[from][j];
                moveCost[houseIdx] = absInt(shelterPos[1]    - houseIdx)
                                   - absInt(shelterPos[from] - houseIdx);
            }

            // 초과분의 4 배만 모아둔다. 비율이 좋은 집을 고를 여유는 주면서
            // 목록 뒤쪽(손해가 큰 집들)은 아예 건드리지 않는다.
            // 배수를 2/3/4/6 으로 재보니 4 부터 점수가 평평해진다 (1620.3 / 1618.4 / 1618.3 / 1618.3).
            collectCandidates(shelterHouse[from], shelterHouseCnt[from],
                              (shelterPeople[from] - CAP) * 4);

            while (shelterPeople[from] > CAP) {
                int box = pickCheapestBox();
                if (box == 0) break;             // 방어. 정상 입력에서는 도달하지 않는다

                int houseIdx = candBox[box][candBoxTaken[box]++];
                assignedTo[houseIdx]  = 1;
                shelterPeople[from]  -= peopleAt[houseIdx];
                shelterPeople[1]     += peopleAt[houseIdx];
            }
        }

        // ── 3) B 의 초과분을 A / C 중 싼 쪽으로 ──
        if (shelterPeople[1] > CAP) {

            // 2 단계에서 A, C 의 집들이 B 로 넘어왔으므로 목록을 다시 만든다.
            // 칸 인덱스 오름차순이어야 collectCandidates 의 전제가 성립한다.
            shelterHouseCnt[1] = 0;
            for (int i = 0; i < LINE; ++i)
                if (peopleAt[i] && assignedTo[i] == 1)
                    shelterHouse[1][shelterHouseCnt[1]++] = i;

            for (int j = 0; j < shelterHouseCnt[1]; ++j) {
                int houseIdx = shelterHouse[1][j];
                int toA = absInt(shelterPos[0] - houseIdx) - absInt(shelterPos[1] - houseIdx);
                int toC = absInt(shelterPos[2] - houseIdx) - absInt(shelterPos[1] - houseIdx);
                if (toA <= toC) { moveCost[houseIdx] = toA; moveTo[houseIdx] = 0; }
                else            { moveCost[houseIdx] = toC; moveTo[houseIdx] = 2; }
            }

            // 목적지가 꽉 차서 건너뛰는 집이 있으므로 여유를 더 준다.
            collectCandidates(shelterHouse[1], shelterHouseCnt[1],
                              (shelterPeople[1] - CAP) * 4);

            // 1 차: 각자 싼 쪽으로. 그 쪽이 꽉 찼으면 건너뛴다.
            // (2 단계에서 A 로부터 넘어온 집은 moveCost 가 음수라 먼저 뽑히는데,
            //  A 는 이미 꽉 차 있으므로 대부분 여기서 걸러진다.)
            while (shelterPeople[1] > CAP) {
                int box = pickCheapestBox();
                if (box == 0) break;

                int houseIdx = candBox[box][candBoxTaken[box]++];
                int to = moveTo[houseIdx];
                if (shelterPeople[to] + peopleAt[houseIdx] <= CAP) {
                    assignedTo[houseIdx] = to;
                    shelterPeople[1]    -= peopleAt[houseIdx];
                    shelterPeople[to]   += peopleAt[houseIdx];
                }
            }

            // 2 차: 1 차로 부족하면 자리가 있는 쪽으로 보낸다.
            // 위 부등식으로 자리는 반드시 남아 있다.
            if (shelterPeople[1] > CAP) {
                collectCandidates(shelterHouse[1], shelterHouseCnt[1], 0x3fffffff);  // 예산 없이 전체

                while (shelterPeople[1] > CAP) {
                    int box = pickCheapestBox();
                    if (box == 0) break;

                    int houseIdx = candBox[box][candBoxTaken[box]++];
                    if (assignedTo[houseIdx] != 1) continue;      // 1 차에서 이미 나간 집

                    int to = -1;
                    if      (shelterPeople[0] + peopleAt[houseIdx] <= CAP) to = 0;
                    else if (shelterPeople[2] + peopleAt[houseIdx] <= CAP) to = 2;
                    if (to < 0) continue;

                    assignedTo[houseIdx] = to;
                    shelterPeople[1]    -= peopleAt[houseIdx];
                    shelterPeople[to]   += peopleAt[houseIdx];
                }
            }
        }

        // ── 4) 결과 기록 ──
        // 채점기는 쉘터의 "위치" 와 비교한다. 0/1/2 가 아니다.
        for (int i = 0; i < LINE; ++i)
            if (peopleAt[i]) house[floor][i] = shelterPos[assignedTo[i]];
    }
}
