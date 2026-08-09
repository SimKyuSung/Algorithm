/*
    참 최적값 계산기 (검증용, 제출 대상 아님)

    채점기(main.cpp)의 build() 를 그대로 복제해 같은 인스턴스를 만든 뒤,
    LOSS 의 이론적 최소값을 "증명과 함께" 구한다.

    ── 문제의 정체 ────────────────────────────────────────────────
    유저 25만 명을 기지국 4개에 배정. 비용은 제곱거리, 기지국당 정원 67500.
    이건 수송문제(transportation problem)다.

        minimize  sum_i sum_k  d2[i][k] * x[i][k]
        s.t.      sum_k x[i][k] = 1        (유저는 정확히 한 곳)
                  sum_i x[i][k] <= CAP     (기지국 정원)
                  x >= 0

    LP 완화가 정수 최적해를 갖는 구조라, 근사가 아니라 정확한 최적을 구할 수 있다.

    ── 푸는 방법 ─────────────────────────────────────────────────
    최소비용유량의 최적성 조건: 잔여 그래프에 음수 사이클이 없으면 최적.

    유저 노드가 25만 개지만, "기지국 k 에 있는 유저 하나를 m 으로 옮긴다" 는
    복합 동작으로 접으면 노드가 기지국 4개로 줄어든다. 그 최소 비용이

        delta[k][m] = min over (k 에 배정된 유저 i) of ( d2[i][m] - d2[i][k] )

    이고, 4개 노드 위의 단순 사이클은 전부 열거할 수 있다(길이 2,3,4).
    정원 여유가 있는 기지국으로 흘려보내는 경로도 사이클의 일종이라 같이 본다.
    (총 정원 270000 > 유저 250000 이므로 여유 있는 기지국이 반드시 하나는 있다.)

    ── 최적임을 증명하는 법 ───────────────────────────────────────
    기지국마다 쌍대변수 lambda[k] >= 0 을 잡으면 임의의 lambda 에 대해

        L(lambda) = sum_i min_k ( d2[i][k] + lambda[k] ) - CAP * sum_k lambda[k]

    가 항상 최적값 이하다(라그랑주 완화). 따라서 우리 해의 비용이 어떤 lambda 에서
    L(lambda) 와 정확히 같으면 그 해가 최적이라는 증명이 된다.

    상보여유조건이 성립하면 자동으로 같아진다. 필요한 조건은 셋:
      (a) lambda[k] >= 0
      (b) 정원이 안 찬 기지국은 lambda[k] == 0
      (c) 모든 유저가 d2 + lambda 기준으로 자기 기지국을 최선으로 삼음

    (c) 를 유저 전체가 아니라 기지국 단위로 쓰면 lambda[k] - lambda[m] <= delta[k][m]
    이라는 차분 제약이 되고, 이건 최단경로로 푼다. 음수 사이클이 없어야 풀리는데
    앞 단계에서 이미 다 제거했으므로 반드시 풀린다.
*/

#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

#define CSIZE   5000
#define UCNT    250000
#define CAP     67500
#define NBASE   4
#define INF     0x3f3f3f3f3f3f3f3fLL

// ── 채점기 build() 복제 ─────────────────────────────────────────

static char CELL[CSIZE][CSIZE];
static int  NB[NBASE][2];
static int  seed = 3;

static int pseudo_rand(void)
{
    seed = seed * 214011 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

static void build(void)
{
    for (int y = 0; y < CSIZE; y++)
        for (int x = 0; x < CSIZE; x++)
            CELL[y][x] = 0;

    for (int c = 0; c < NBASE;) {
        int x = pseudo_rand() % CSIZE;
        int y = pseudo_rand() % CSIZE;
        if (CELL[y][x] != 0) continue;
        CELL[y][x] = -(c + 1);
        NB[c][0] = x; NB[c][1] = y;
        c++;
    }

    for (int c = 0; c < UCNT;) {
        int x = pseudo_rand() % CSIZE;
        int y = pseudo_rand() % CSIZE;
        if (CELL[y][x] != 0) continue;
        CELL[y][x] = 1 + (pseudo_rand() % 4);
        c++;
    }
}

// ── 인스턴스 ────────────────────────────────────────────────────

static int       ucnt;
static long long d2[UCNT][NBASE];   // 유저 i 에서 기지국 k 까지의 제곱거리
static int       asg[UCNT];         // 현재 배정
static int       cnt[NBASE];        // 기지국별 인원

static void loadInstance(void)
{
    static int ux[UCNT], uy[UCNT];
    ucnt = 0;
    for (int y = 0; y < CSIZE; y++)
        for (int x = 0; x < CSIZE; x++)
            if (CELL[y][x] > 0) { ux[ucnt] = x; uy[ucnt] = y; ucnt++; }

    for (int i = 0; i < ucnt; i++)
        for (int k = 0; k < NBASE; k++) {
            long long dx = NB[k][0] - ux[i];
            long long dy = NB[k][1] - uy[i];
            d2[i][k] = dx * dx + dy * dy;
        }
}

static long long totalCost(void)
{
    long long t = 0;
    for (int i = 0; i < ucnt; i++) t += d2[i][asg[i]];
    return t;
}

static void recount(void)
{
    for (int k = 0; k < NBASE; k++) cnt[k] = 0;
    for (int i = 0; i < ucnt; i++) cnt[asg[i]]++;
}

// ── 1단계: 초기 실행가능 해 ──────────────────────────────────────
// 가격조정(라그랑주)으로 최적 근처까지 간 뒤 초과 인원만 정리한다.
// 어떤 실행가능 해에서 출발해도 2단계가 최적으로 끌고 가지만,
// 좋은 출발점일수록 2단계 반복이 줄어든다.

static void repairOverflow(void)
{
    recount();
    for (int pass = 0; pass < 8; pass++) {
        int done = 1;
        for (int k = 0; k < NBASE; k++) {
            if (cnt[k] <= CAP) continue;
            done = 0;

            // 내보낼 때 손해가 가장 적은 유저부터 뺀다.
            vector<pair<long long, int> > cand;
            cand.reserve(cnt[k]);
            for (int i = 0; i < ucnt; i++) {
                if (asg[i] != k) continue;
                long long best = INF;
                for (int m = 0; m < NBASE; m++) {
                    if (m == k || cnt[m] >= CAP) continue;
                    long long p = d2[i][m] - d2[i][k];
                    if (p < best) best = p;
                }
                if (best != INF) cand.push_back(make_pair(best, i));
            }
            sort(cand.begin(), cand.end());

            for (size_t t = 0; t < cand.size() && cnt[k] > CAP; t++) {
                int i = cand[t].second, dst = -1;
                for (int m = 0; m < NBASE; m++) {
                    if (m == k || cnt[m] >= CAP) continue;
                    if (dst < 0 || d2[i][m] < d2[i][dst]) dst = m;
                }
                if (dst < 0) break;
                asg[i] = dst; cnt[k]--; cnt[dst]++;
            }
        }
        if (done) break;
    }
}

static void warmStart(int iters)
{
    double lam[NBASE] = {0, 0, 0, 0};
    double bestLam[NBASE] = {0, 0, 0, 0};
    double bestDual = -1e300, ub = 1e300;
    static int save[UCNT];

    for (int it = 0; it < iters; it++) {
        // 현재 가격으로 배정하고 쌍대값을 잰다.
        double lag = 0;
        for (int k = 0; k < NBASE; k++) cnt[k] = 0;
        for (int i = 0; i < ucnt; i++) {
            int b = 0;
            double best = (double)d2[i][0] + lam[0];
            for (int k = 1; k < NBASE; k++) {
                double v = (double)d2[i][k] + lam[k];
                if (v < best) { best = v; b = k; }
            }
            asg[i] = b; cnt[b]++; lag += best;
        }
        for (int k = 0; k < NBASE; k++) lag -= (double)CAP * lam[k];
        if (lag > bestDual) {
            bestDual = lag;
            for (int k = 0; k < NBASE; k++) bestLam[k] = lam[k];
        }

        // 스텝 크기에 쓸 상계를 가끔 갱신한다.
        if (it % 25 == 0) {
            for (int i = 0; i < ucnt; i++) save[i] = asg[i];
            repairOverflow();
            double p = (double)totalCost();
            if (p < ub) ub = p;
            for (int i = 0; i < ucnt; i++) asg[i] = save[i];
            recount();
        }

        double g2 = 0;
        for (int k = 0; k < NBASE; k++) {
            double g = cnt[k] - (double)CAP;
            g2 += g * g;
        }
        if (g2 < 1e-9) break;   // 이미 정원 만족

        // 열화가 심한 기지국의 가격을 더 많이 올린다(부분경사법, Polyak 스텝).
        double step = 1.6 * (ub - bestDual) / g2;
        for (int k = 0; k < NBASE; k++) {
            lam[k] += step * (cnt[k] - (double)CAP);
            if (lam[k] < 0) lam[k] = 0;
        }
    }

    // 가장 좋았던 가격으로 최종 배정 후 초과분 정리.
    for (int i = 0; i < ucnt; i++) {
        int b = 0;
        double best = (double)d2[i][0] + bestLam[0];
        for (int k = 1; k < NBASE; k++) {
            double v = (double)d2[i][k] + bestLam[k];
            if (v < best) { best = v; b = k; }
        }
        asg[i] = b;
    }
    repairOverflow();
}

// ── 2단계: 음수 사이클 제거 ─────────────────────────────────────

static long long delta[NBASE][NBASE];   // k 의 유저 하나를 m 으로 옮기는 최소 추가비용

static void computeDelta(void)
{
    for (int k = 0; k < NBASE; k++)
        for (int m = 0; m < NBASE; m++)
            delta[k][m] = INF;

    for (int i = 0; i < ucnt; i++) {
        int k = asg[i];
        for (int m = 0; m < NBASE; m++) {
            if (m == k) continue;
            long long p = d2[i][m] - d2[i][k];
            if (p < delta[k][m]) delta[k][m] = p;
        }
    }
}

/*
    arcs 를 따라 유저를 t 명씩 한꺼번에 옮긴다.
    arcs[j] = (a, b) 는 "기지국 a 의 유저 하나를 b 로" 를 뜻한다.
    사이클이면 인원이 보존되고, 경로면 시작 기지국이 줄고 끝 기지국이 는다.

    한 명씩 반복하면 매번 25만 명을 다시 훑어야 해서 느리다.
    각 arc 마다 이동 비용을 정렬해두고, t 번째 유저들까지 옮겼을 때의
    한계 이득이 양수인 동안 t 를 늘리면 한 번에 처리된다.
*/
static long long applyArcs(const int (*arcs)[2], int narc, int limit)
{
    static vector<pair<long long, int> > g[NBASE];
    for (int j = 0; j < narc; j++) g[j].clear();

    for (int i = 0; i < ucnt; i++) {
        int k = asg[i];
        for (int j = 0; j < narc; j++)
            if (arcs[j][0] == k)
                g[j].push_back(make_pair(d2[i][arcs[j][1]] - d2[i][k], i));
    }

    int maxT = limit;
    for (int j = 0; j < narc; j++) {
        sort(g[j].begin(), g[j].end());
        if ((int)g[j].size() < maxT) maxT = (int)g[j].size();
    }

    // 한계 비용이 음수인 동안만 인원을 늘린다.
    int t = 0;
    long long gain = 0, acc = 0;
    while (t < maxT) {
        long long marginal = 0;
        for (int j = 0; j < narc; j++) marginal += g[j][t].first;
        if (marginal >= 0) break;
        acc += marginal;
        t++;
        gain = -acc;
    }
    if (t == 0) return 0;

    for (int j = 0; j < narc; j++)
        for (int s = 0; s < t; s++)
            asg[g[j][s].second] = arcs[j][1];

    recount();
    return gain;
}

// 개선 가능한 사이클/경로를 전부 열거해 가장 이득이 큰 것부터 적용한다.
static long long cancelNegativeCycles(void)
{
    long long improved = 0;

    while (1) {
        recount();
        computeDelta();

        int    bestArcs[NBASE][2], bestN = 0, bestLimit = 0;
        long long bestVal = 0;   // delta 합. 음수여야 개선.

        // 길이 2,3,4 사이클: 인원 변화 없음, 항상 실행가능.
        for (int a = 0; a < NBASE; a++)
            for (int b = 0; b < NBASE; b++) {
                if (b == a) continue;
                if (delta[a][b] >= INF || delta[b][a] >= INF) continue;
                long long v = delta[a][b] + delta[b][a];
                if (v < bestVal) {
                    bestVal = v; bestN = 2; bestLimit = UCNT;
                    bestArcs[0][0] = a; bestArcs[0][1] = b;
                    bestArcs[1][0] = b; bestArcs[1][1] = a;
                }
                for (int c = 0; c < NBASE; c++) {
                    if (c == a || c == b) continue;
                    if (delta[b][c] >= INF || delta[c][a] >= INF) continue;
                    long long v3 = delta[a][b] + delta[b][c] + delta[c][a];
                    if (v3 < bestVal) {
                        bestVal = v3; bestN = 3; bestLimit = UCNT;
                        bestArcs[0][0] = a; bestArcs[0][1] = b;
                        bestArcs[1][0] = b; bestArcs[1][1] = c;
                        bestArcs[2][0] = c; bestArcs[2][1] = a;
                    }
                    for (int d = 0; d < NBASE; d++) {
                        if (d == a || d == b || d == c) continue;
                        if (delta[c][d] >= INF || delta[d][a] >= INF) continue;
                        long long v4 = delta[a][b] + delta[b][c] + delta[c][d] + delta[d][a];
                        if (v4 < bestVal) {
                            bestVal = v4; bestN = 4; bestLimit = UCNT;
                            bestArcs[0][0] = a; bestArcs[0][1] = b;
                            bestArcs[1][0] = b; bestArcs[1][1] = c;
                            bestArcs[2][0] = c; bestArcs[2][1] = d;
                            bestArcs[3][0] = d; bestArcs[3][1] = a;
                        }
                    }
                }
            }

        // 정원 여유가 있는 기지국으로 흘려보내는 경로 (길이 1,2,3).
        for (int a = 0; a < NBASE; a++)
            for (int b = 0; b < NBASE; b++) {
                if (b == a || delta[a][b] >= INF) continue;
                if (cnt[b] < CAP && delta[a][b] < bestVal) {
                    bestVal = delta[a][b]; bestN = 1; bestLimit = CAP - cnt[b];
                    bestArcs[0][0] = a; bestArcs[0][1] = b;
                }
                for (int c = 0; c < NBASE; c++) {
                    if (c == a || c == b || delta[b][c] >= INF) continue;
                    long long v2 = delta[a][b] + delta[b][c];
                    if (cnt[c] < CAP && v2 < bestVal) {
                        bestVal = v2; bestN = 2; bestLimit = CAP - cnt[c];
                        bestArcs[0][0] = a; bestArcs[0][1] = b;
                        bestArcs[1][0] = b; bestArcs[1][1] = c;
                    }
                    for (int d = 0; d < NBASE; d++) {
                        if (d == a || d == b || d == c || delta[c][d] >= INF) continue;
                        long long v3 = delta[a][b] + delta[b][c] + delta[c][d];
                        if (cnt[d] < CAP && v3 < bestVal) {
                            bestVal = v3; bestN = 3; bestLimit = CAP - cnt[d];
                            bestArcs[0][0] = a; bestArcs[0][1] = b;
                            bestArcs[1][0] = b; bestArcs[1][1] = c;
                            bestArcs[2][0] = c; bestArcs[2][1] = d;
                        }
                    }
                }
            }

        if (bestN == 0) break;                       // 음수 사이클 없음 = 최적
        long long g = applyArcs(bestArcs, bestN, bestLimit);
        if (g <= 0) break;                           // 더 줄일 게 없음
        improved += g;
    }

    return improved;
}

// ── 3단계: 최적성 증명 ──────────────────────────────────────────
/*
    lambda[k] - lambda[m] <= delta[k][m] 을 만족하는 lambda 를 최단경로로 찾는다.
    (m -> k 방향 가중치 delta[k][m] 인 그래프의 최단거리)
    정원이 안 찬 기지국을 0 으로 고정해 출발점으로 삼는다.
*/
static bool certify(long long primal, double *dualOut)
{
    computeDelta();

    long long lam[NBASE];
    for (int k = 0; k < NBASE; k++) lam[k] = (cnt[k] < CAP) ? 0 : INF;

    for (int pass = 0; pass < NBASE; pass++)
        for (int m = 0; m < NBASE; m++) {
            if (lam[m] >= INF) continue;
            for (int k = 0; k < NBASE; k++) {
                if (k == m || delta[k][m] >= INF) continue;
                if (lam[m] + delta[k][m] < lam[k]) lam[k] = lam[m] + delta[k][m];
            }
        }

    for (int k = 0; k < NBASE; k++) {
        if (lam[k] >= INF) { printf("  [증명실패] lambda 를 못 정함\n"); return false; }
        if (lam[k] < 0)    { printf("  [증명실패] lambda[%d] = %lld < 0\n", k, lam[k]); return false; }
        if (cnt[k] < CAP && lam[k] != 0) { printf("  [증명실패] 여유 기지국인데 lambda != 0\n"); return false; }
    }

    // (c) 모든 유저가 d2 + lambda 기준으로 자기 기지국을 최선으로 삼는가.
    long long sumMin = 0;
    for (int i = 0; i < ucnt; i++) {
        long long best = d2[i][0] + lam[0];
        for (int k = 1; k < NBASE; k++) {
            long long v = d2[i][k] + lam[k];
            if (v < best) best = v;
        }
        if (d2[i][asg[i]] + lam[asg[i]] != best) {
            printf("  [증명실패] 유저 %d 가 최선이 아님\n", i);
            return false;
        }
        sumMin += best;
    }

    double dual = (double)sumMin;
    for (int k = 0; k < NBASE; k++) dual -= (double)CAP * (double)lam[k];
    *dualOut = dual;

    return dual == (double)primal;
}

// ── 메인 ────────────────────────────────────────────────────────

int main(int argc, char **argv)
{
    int tc = 10;
    if (argc > 1) tc = atoi(argv[1]);

    double sumOpt = 0;
    clock_t start = clock();

    printf("TC   최적 LOSS       기지국별 인원                검증\n");
    printf("---------------------------------------------------------------\n");

    for (int c = 0; c < tc; c++) {
        build();
        loadInstance();

        warmStart(200);
        long long before = totalCost();
        cancelNegativeCycles();
        long long opt = totalCost();

        double dual = 0;
        bool ok = certify(opt, &dual);

        printf("%-4d %.6e   %6d %6d %6d %6d   %s  (초기해 대비 -%.3f%%)\n",
               c, (double)opt, cnt[0], cnt[1], cnt[2], cnt[3],
               ok ? "최적 증명됨" : "증명 실패  ",
               100.0 * (double)(before - opt) / (double)before);

        sumOpt += (double)opt;
    }

    printf("---------------------------------------------------------------\n");
    printf("최적 LOSS 합계 : %.6e\n", sumOpt);
    printf("통과 기준      : %.6e  (최적 대비 여유 %.2f%%)\n",
           6.8e12, 100.0 * (6.8e12 - sumOpt) / sumOpt);
    printf("소요 시간      : %.2f 초\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
