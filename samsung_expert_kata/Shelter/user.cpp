// Shelter — 제출 파일
// STL 금지: 헤더 include 없이 고정 크기 전역 배열만 쓴다.
//
// ── 측정으로 확정한 것 ────────────────────────────────────────────────
//   하한 1503 : 용량을 무시하고 각 집을 가장 가까운 쉘터에 붙였을 때의 점수.
//   천장 1668 : 연속 구간 3분할(경계 2개)을 완전탐색했을 때의 최선.
//               기준선 1640 을 못 넘는다  =>  답은 구간 분할이 아니다.
//   채점기는 비용을 "집 단위" 로 더하고(main.cpp:48), 용량은 "사람 단위" 로 센다(main.cpp:46).
//               =>  같은 거리 손해라면 인원이 많은 집을 옮기는 쪽이 자리를 더 많이 비운다.
//               =>  옮길 우선순위 = (늘어나는 거리) / (그 집의 인원), 작은 것부터.
//
// ── 알고리즘 ─────────────────────────────────────────────────────────
//   1) 각 집을 가장 가까운 쉘터에 배정한다.
//   2) A 와 C 의 초과분을 B 로 옮긴다. 이때 B 가 용량을 넘어도 무시한다.
//      채점기는 assign() 이 끝난 뒤 최종 상태만 보므로(main.cpp:35~57) 중간 위반은 무해하다.
//      이 완화 덕분에 "어느 쪽을 먼저 처리할지" 라는 순서 문제가 통째로 사라진다.
//      A 의 집은 갈 곳이 B 뿐이고 C 도 마찬가지라, 여기서는 목적지에 선택의 여지가 없다.
//   3) B 의 초과분을 A / C 중 그 집에게 싼 쪽으로 옮긴다.
//      자리가 항상 충분한 근거:
//        필요한 자리 = (총합 - A' - C') - CAP
//        있는 자리   = (CAP - A') + (CAP - C')
//        차이        = 3*CAP - 총합 = 60000 - 약 50000 > 0
//      (총합은 집 10000 채 x 평균 5 명 = 약 50000. 표준편차가 258 이라 60000 은 38 시그마.)
//
// ── 정렬을 쓰지 않는 이유 ────────────────────────────────────────────
//   층이 10000 개라 층마다 정렬을 돌리면 시간이 안 나온다.
//   대신 두 가지 성질을 쓴다.
//     (a) 한 쉘터가 담당하는 집을 칸 인덱스 순으로 늘어놓으면, "옮길 때 늘어나는 거리" 는
//         양 끝이 작고 가운데가 큰 텐트 모양이다. 거리 함수가 구간별 1차식이기 때문이다.
//         => 양쪽 끝에서 작은 쪽부터 집어오면 그 자체가 오름차순 순회다.
//     (b) 인원은 1~9 뿐이다. 인원별로 9 개 큐에 나눠 담으면 각 큐가 이미 정렬된 상태다.
//         => 매번 9 개 머리 중 (늘어나는 거리)/(인원) 최소만 고르면 된다.
//   나눗셈은 정수에서 버려지므로 비교는 교차 곱셈으로 한다.

const int FLOOR = 10000;
const int LINE  = 10000;
const int CAP   = 20000;   // 쉘터 1 개의 수용 인원

static int popn[LINE];     // 각 칸의 인원 (쉘터 칸은 0)
static int owner[LINE];    // 각 집이 현재 속한 쉘터 (0/1/2)
static int incv[LINE];     // 이번 단계에서 옮길 때 늘어나는 거리
static int tgtv[LINE];     // 이번 단계에서 옮길 목적지 (3 단계 전용)

static int lst[3][LINE];   // 쉘터별 담당 집 목록. 항상 칸 인덱스 오름차순이어야 한다 — (a) 의 전제
static int lsz[3];
static int load[3];        // 쉘터별 인원 합

static int que[10][LINE];  // 인원(1~9) 별 후보 큐. 각 큐는 incv 오름차순이 된다
static int qsz[10], qhead[10];

static inline int iabs(int a) { return a < 0 ? -a : a; }

// list 를 incv 오름차순으로 훑으면서 인원별 큐에 나눠 담는다.
// incv 가 텐트 모양이라 양 끝에서 작은 쪽부터 집어오면 오름차순이 된다.
//
// budget: 큐에 모아야 할 인원. 이만큼 모이면 뒤는 볼 필요가 없다.
//   incv 오름차순으로 담으므로 잘려나간 집들은 전부 담은 집들보다 손해가 크다.
//   초과분만큼만 모아두면 그 안에서 반드시 해소되므로 정답성은 유지된다.
//   목록 전체를 훑으면 층당 1 만 회인데, 실제로 옮기는 집은 그 일부뿐이다.
static void fillQueues(const int* list, int n, int budget)
{
    for (int p = 1; p <= 9; ++p) { qsz[p] = 0; qhead[p] = 0; }

    int L = 0, R = n - 1, got = 0;
    while (L <= R && got < budget) {
        int h;
        if (incv[list[L]] <= incv[list[R]]) h = list[L++];
        else                                h = list[R--];
        que[popn[h]][qsz[popn[h]]++] = h;
        got += popn[h];
    }
}

// 큐 9 개의 머리 중 (늘어나는 거리)/(인원) 이 가장 작은 것의 인원값을 돌려준다.
// 후보가 하나도 없으면 0.
static int pickCheapest()
{
    int best = 0;
    for (int p = 1; p <= 9; ++p) {
        if (qhead[p] >= qsz[p]) continue;
        if (best == 0) { best = p; continue; }

        int a = incv[que[p][qhead[p]]];
        int b = incv[que[best][qhead[best]]];
        // a/p < b/best  <=>  a*best < b*p   (p, best 가 양수라 부등호 방향이 보존된다)
        if (a * best < b * p) best = p;
    }
    return best;
}

void assign(int house[FLOOR][10000])
{
    for (int f = 0; f < FLOOR; ++f) {

        // 쉘터 위치. 앞에서부터 훑으므로 s[] 는 자동으로 오름차순이다.
        int s[3];
        int cnt = 0;
        for (int i = 0; i < LINE; ++i) {
            popn[i] = house[f][i];
            if (popn[i] == 0) s[cnt++] = i;
        }

        // ── 1) 최근접 배정 ──
        lsz[0] = lsz[1] = lsz[2] = 0;
        load[0] = load[1] = load[2] = 0;
        for (int i = 0; i < LINE; ++i) {
            if (popn[i] == 0) continue;

            int d0 = iabs(s[0] - i);
            int d1 = iabs(s[1] - i);
            int d2 = iabs(s[2] - i);

            int w = (d0 <= d1) ? 0 : 1;
            if (d2 < ((w == 0) ? d0 : d1)) w = 2;

            owner[i] = w;
            lst[w][lsz[w]++] = i;
            load[w] += popn[i];
        }

        // ── 2) A 와 C 의 초과분을 B 로 (B 가 넘쳐도 무시) ──
        for (int k = 0; k < 2; ++k) {
            int src = (k == 0) ? 0 : 2;
            if (load[src] <= CAP) continue;

            for (int j = 0; j < lsz[src]; ++j) {
                int h = lst[src][j];
                incv[h] = iabs(s[1] - h) - iabs(s[src] - h);
            }
            // 초과분의 4 배만 모아둔다. 비율이 좋은 집을 고를 여유는 주면서
            // 목록 뒤쪽(손해가 큰 집들)은 아예 건드리지 않는다.
            // 배수를 2/3/4/6 으로 재보니 4 부터 점수가 평평해진다 (1620.3 / 1618.4 / 1618.3 / 1618.3).
            fillQueues(lst[src], lsz[src], (load[src] - CAP) * 4);

            while (load[src] > CAP) {
                int p = pickCheapest();
                if (p == 0) break;              // 방어. 정상 입력에서는 도달하지 않는다
                int h = que[p][qhead[p]++];
                owner[h]   = 1;
                load[src] -= popn[h];
                load[1]   += popn[h];
            }
        }

        // ── 3) B 의 초과분을 A / C 중 싼 쪽으로 ──
        if (load[1] > CAP) {

            // 2 단계에서 A, C 의 집들이 B 로 넘어왔으므로 목록을 다시 만든다.
            // 인덱스 오름차순이어야 fillQueues 의 전제가 성립한다.
            lsz[1] = 0;
            for (int i = 0; i < LINE; ++i)
                if (popn[i] && owner[i] == 1) lst[1][lsz[1]++] = i;

            for (int j = 0; j < lsz[1]; ++j) {
                int h  = lst[1][j];
                int dA = iabs(s[0] - h) - iabs(s[1] - h);
                int dC = iabs(s[2] - h) - iabs(s[1] - h);
                if (dA <= dC) { incv[h] = dA; tgtv[h] = 0; }
                else          { incv[h] = dC; tgtv[h] = 2; }
            }
            // 목적지가 꽉 차서 건너뛰는 집이 있으므로 여유를 더 준다.
            fillQueues(lst[1], lsz[1], (load[1] - CAP) * 4);

            // 1 차: 각자 싼 쪽으로. 그 쪽이 꽉 찼으면 건너뛴다.
            // (2 단계에서 A 로부터 넘어온 집은 incv 가 음수라 먼저 뽑히는데,
            //  A 는 이미 꽉 차 있으므로 대부분 여기서 걸러진다.)
            while (load[1] > CAP) {
                int p = pickCheapest();
                if (p == 0) break;
                int h = que[p][qhead[p]++];
                int t = tgtv[h];
                if (load[t] + popn[h] <= CAP) {
                    owner[h] = t;
                    load[1] -= popn[h];
                    load[t] += popn[h];
                }
            }

            // 2 차: 1 차로 부족하면 자리가 있는 쪽으로 보낸다.
            // 위 부등식으로 자리는 반드시 남아 있다.
            if (load[1] > CAP) {
                fillQueues(lst[1], lsz[1], 0x3fffffff);   // 이번엔 예산 없이 전체
                while (load[1] > CAP) {
                    int p = pickCheapest();
                    if (p == 0) break;
                    int h = que[p][qhead[p]++];
                    if (owner[h] != 1) continue;          // 1 차에서 이미 나간 집

                    int t = -1;
                    if      (load[0] + popn[h] <= CAP) t = 0;
                    else if (load[2] + popn[h] <= CAP) t = 2;
                    if (t < 0) continue;

                    owner[h] = t;
                    load[1] -= popn[h];
                    load[t] += popn[h];
                }
            }
        }

        // ── 4) 결과 기록 ──
        // 채점기는 쉘터의 "위치" 와 비교한다 (main.cpp:44). 0/1/2 가 아니다.
        for (int i = 0; i < LINE; ++i)
            if (popn[i]) house[f][i] = s[owner[i]];
    }
}
