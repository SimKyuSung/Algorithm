// Shelter 검증 도구 — 제출 대상이 아니다. 독립 main() 을 가지며 STL 자유.
//
// 하는 일:
//   채점기(main.cpp)와 완전히 동일한 순서로 앞쪽 몇 개 층을 생성한 뒤,
//   각 층에 대해 "구간 경계 두 개" 의 가능한 모든 조합을 완전탐색해서
//   구간 분할 방식으로 낼 수 있는 최소 비용을 구한다.
//
//   비교 대상으로 두 가지를 같이 낸다:
//     - 최근접 비용 : 용량 제한을 완전히 무시하고 각 집을 가장 가까운 쉘터에 붙인 값 (도달 불가 하한)
//     - 최적 비용   : 용량 제한을 지키면서 연속 구간 3분할로 낼 수 있는 최소값
//
//   주의: "배치는 연속 구간 3분할이다" 는 이 도구가 **가정**하는 것이지 증명한 것이 아니다.
//         그 가정이 맞는지는 별도로 따져야 한다.
//
// 쓰는 법:
//   ./optimal <seed> <검사할 층 수>
//   예) ./optimal 3 20
//
// 주의:
//   채점기와 같은 srand(seed) 시퀀스를 쓰므로, 여기서 나오는 0번 층은
//   채점기의 0번 층과 정확히 같은 층이다. 층을 건너뛰면 시퀀스가 어긋나므로
//   항상 앞에서부터 연속으로만 검사한다.

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

static const int N = 10000;      // 한 층의 칸 수
static const int CAP = 20000;    // 쉘터 1개의 수용 인원
static const long long INF = (1LL << 62);

int main(int argc, char** argv)
{
    int seed = (argc > 1) ? atoi(argv[1]) : 3;
    int floors = (argc > 2) ? atoi(argv[2]) : 10;

    srand(seed);

    vector<int> w(N);              // w[i] = i 번 칸의 인원 (쉘터는 0)
    vector<long long> W(N + 1);    // W[k] = i < k 의 인원 합
    vector<long long> D[3];        // D[j][k] = i < k 이고 집인 칸들의 |s[j] - i| 합
    for (int j = 0; j < 3; j++) D[j].assign(N + 1, 0);

    double sumNearest = 0.0, sumOptimal = 0.0;
    int solved = 0;

    // 층 수가 많으면 표는 노이즈다. 평균만 본다.
    bool verbose = (floors <= 100);

    if (verbose) {
        printf("floor |   s0    s1    s2 |   최근접     최적    차이 |  중점경계   최적경계  |    이동\n");
        printf("------+------------------+--------------------------+-----------------------+--------------\n");
    }

    for (int f = 0; f < floors; f++)
    {
        // ---- 채점기와 동일한 층 생성 ----
        int s[3];
        for (int c = 0; c < N; c++) w[c] = 1 + (rand() % 9);
        for (int c = 0; c < 3;)
        {
            int r = rand() % N;
            if (w[r] == 0) continue;   // 이미 쉘터로 뽑힌 칸
            w[r] = 0;
            s[c++] = r;
        }
        // 구간으로 자르려면 위치 순서가 필요하다. 채점기는 뽑은 순서대로 담을 뿐이다.
        sort(s, s + 3);

        // ---- 누적합 ----
        W[0] = 0;
        for (int j = 0; j < 3; j++) D[j][0] = 0;
        for (int k = 0; k < N; k++)
        {
            W[k + 1] = W[k] + w[k];
            for (int j = 0; j < 3; j++)
                D[j][k + 1] = D[j][k] + (w[k] ? abs(s[j] - k) : 0);
        }
        long long total = W[N];

        // ---- 참고값 1: 용량 무시, 각 집을 가장 가까운 쉘터로 ----
        long long nearest = 0;
        for (int k = 0; k < N; k++)
        {
            if (!w[k]) continue;
            long long d = abs(s[0] - k);
            d = min(d, (long long)abs(s[1] - k));
            d = min(d, (long long)abs(s[2] - k));
            nearest += d;
        }

        // ---- 참고값 2: 중점 경계 (용량을 안 볼 때의 최적 경계) ----
        int m1 = (s[0] + s[1] + 1) / 2;
        int m2 = (s[1] + s[2] + 1) / 2;

        // ---- 완전탐색: 경계 b1 (A|B), b2 (B|C) 의 모든 조합 ----
        //   A = [0, b1), B = [b1, b2), C = [b2, N)
        //   제약: W[b1] <= CAP,  W[b2]-W[b1] <= CAP,  total-W[b2] <= CAP
        //
        //   가지치기는 제약의 단조성만 이용한다 (인원 합은 구간이 커지면 늘기만 한다).
        //   비용 함수 자체에 대해서는 아무것도 가정하지 않는다 — 그게 완전탐색의 존재 이유다.
        long long best = INF;
        int bestB1 = -1, bestB2 = -1;

        // C 가 넘치지 않으려면 b2 가 이 값 이상이어야 한다
        int b2min = 0;
        while (b2min <= N && total - W[b2min] > CAP) b2min++;

        for (int b1 = 0; b1 <= N; b1++)
        {
            if (W[b1] > CAP) break;                  // A 초과 — 더 오른쪽은 볼 것도 없다

            int lo = max(b1, b2min);
            for (int b2 = lo; b2 <= N; b2++)
            {
                if (W[b2] - W[b1] > CAP) break;      // B 초과 — 더 오른쪽은 볼 것도 없다

                long long cost = D[0][b1]
                               + (D[1][b2] - D[1][b1])
                               + (D[2][N]  - D[2][b2]);
                if (cost < best) { best = cost; bestB1 = b1; bestB2 = b2; }
            }
        }

        if (best == INF)
        {
            printf("%5d | %5d %5d %5d |  (용량 제약을 만족하는 배치가 존재하지 않음)\n",
                   f, s[0], s[1], s[2]);
            continue;
        }

        // 채점기의 SCORE 는 층 비용을 10000 으로 나눈 값의 층 평균이다.
        double nearestScore = (double)nearest / N;
        double bestScore    = (double)best / N;

        if (verbose)
            printf("%5d | %5d %5d %5d | %8.2f %8.2f %7.2f | %5d %5d  %5d %5d | %+6d %+6d\n",
                   f, s[0], s[1], s[2],
                   nearestScore, bestScore, bestScore - nearestScore,
                   m1, m2, bestB1, bestB2,
                   bestB1 - m1, bestB2 - m2);

        sumNearest += nearestScore;
        sumOptimal += bestScore;
        solved++;
    }

    if (solved)
    {
        printf("------+------------------+--------------------------+-----------------------+--------------\n");
        printf("평균 (%d 개 층):  최근접 = %.4f   최적 = %.4f   차이 = %.4f\n",
               solved, sumNearest / solved, sumOptimal / solved,
               (sumOptimal - sumNearest) / solved);
        printf("\n");
        printf("  채점 기준선은 1640 이다.\n");
        printf("  '최근접' 은 아무도 못 넘는 하한.\n");
        printf("  '최적' 은 **연속 구간 3분할로 자를 때** 도달 가능한 최선이다.\n");
        printf("  이 도구는 배치를 구간 분할로 가정하고 탐색한다 — 그 가정 자체는 검증하지 않는다.\n");
    }
    return 0;
}
