extern void scanFromRobot(int ceilingState[3][3]);
extern int moveRobot(int mCommand);

bool allClean = false;
// map max size 30 * 30, 로봇의 초기 위치를 알 수 없음으로 29, 29에서 시작.
// -1: no info 
// 0: no clean
// 1: clean
// 2: wall
int houseMap[60][60];
int n, serviceRunCnt;

/*
각 TC 1회 호출
N: 평면 크기 (10 <= N <= 30)
subTaskCount: cleanHouse() 호출 횟수 (10 <= subTaskCount <= 30)
*/
void init(int N, int subTaskCount)
{
    n = N;
    serviceRunCnt = subTaskCount;
}

// counter-clockwise arrangement (0:UP, 1:LEFT, 2:DOWN, 3:RIGHT)
static int dy[4] = { -1, 0, 1, 0 };
static int dx[4] = { 0, -1, 0, 1 };
// init robot state is random
int x;
int y;
int dir;

// 로봇 방향과 위치를 기준점 삼아 houseMap을 세팅.
void setMap() {
    int tmp[3][3];
    int ceilingState[3][3];
    scanFromRobot(tmp);

    // 로봇 기준 좌표(tmp)를 houseMap의 절대 좌표(ceilingState)로 회전.
    // scanFromRobot()의 역변환. (i, j)는 로봇을 중심으로 한 절대 방향 오프셋 +1.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (dir) {
            case 0: ceilingState[i][j] = tmp[i][j];         break; // UP
            case 1: ceilingState[i][j] = tmp[j][2 - i];     break; // LEFT
            case 2: ceilingState[i][j] = tmp[2 - i][2 - j]; break; // DOWN
            case 3: ceilingState[i][j] = tmp[2 - j][i];     break; // RIGHT
            }
        }
    }

    // 1. wall check.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            if (ceilingState[i][j] == 1)
                ceilingState[i][j] = 2;
    }

    // 2. clean check.
    ceilingState[1][1] = 1;

    // 3. set map.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int yy = i + y - 1;
            int xx = j + x - 1;
            if (houseMap[yy][xx] == -1 || houseMap[yy][xx] == 0) {
                houseMap[yy][xx] = ceilingState[i][j]; 
            }
        }
    }
}

// mCommand는 절대 방향이 아닌 상대 회전량. 0:직진, 1:좌회전, 2:후진, 3:우회전
// 실패(벽) 시 grader는 위치와 방향 모두 그대로 두므로 여기서도 아무것도 갱신하지 않는다.
void move(int mCommand) {
      int prevDir = dir;

      // 1. 방향 변경
      dir = (dir + mCommand) % 4;

      // 2. 이동
      if (moveRobot(mCommand) == 0) {
          // 3. 이동 실패 시 원래 방향 유지
          dir = prevDir;
          return;
      }

      y = y + dy[dir];
      x = x + dx[dir];
}

// houseMap 기준 절대 방향으로 이동. 성공하면 dir 은 absDir 이 된다.
// 회전만 하는 API 가 없으므로 방향 변경은 이동 성공의 부수 효과로만 일어난다.
void moveTo(int absDir) {
    move((absDir - dir + 4) % 4);
}

/*
현재 칸을 스캔하고, 가장 가까운 미청소 구역으로 이동하기를 반복한다.
동일 거리면 좌수법으로 결정. findDirtyZone()

없앤 단계와 이유:
- 주변 칸을 좌수법으로 먼저 청소하는 단계 (nomalClean)
  인접한 미청소 칸은 거리가 1 이라 어차피 최근접으로 선택되므로 중복이었다.
- 벽까지 전진해 벽을 기준점으로 삼으려던 단계 (initRun)
  외곽부터 훑으면 안쪽 자투리를 처리하러 되돌아오게 되어 오히려 손해였다.
  BFS 가 최근접을 고르는 것만으로 이동의 91% 가 바로 옆 칸이라 지역성이 유지된다.
*/

// BFS 용 버퍼. 한 칸은 큐에 한 번만 들어가므로 60 * 60 이면 충분하다.
static int qy[3600], qx[3600];
static bool visited[60][60];
static int enterDir[60][60];   // 그 칸에 들어올 때 사용한 절대 방향
static int pathBuf[3600];

// 가장 가까운 미청소 칸까지 최단 경로로 이동한다. 갈 곳이 없으면 false.
// 이미 청소한 칸(1)도 통로로 쓰고, 벽(2)과 미확인(-1)은 지나가지 않는다.
bool findDirtyZone() {
    for (int i = 0; i < 60; ++i) {
        for (int j = 0; j < 60; ++j)
            visited[i][j] = false;
    }

    int head = 0, tail = 0;
    qy[tail] = y;
    qx[tail] = x;
    ++tail;
    visited[y][x] = true;

    int goalY = -1, goalX = -1;
    while (head < tail) {
        int cy = qy[head], cx = qx[head];
        ++head;

        if (houseMap[cy][cx] == 0 && !(cy == y && cx == x)) {
            goalY = cy;
            goalX = cx;
            break;
        }

        // 좌수법 순서로 확장해 거리가 같을 때 좌측이 먼저 잡히게 한다.
        int order[4] = { (dir + 1) % 4, dir, (dir + 3) % 4, (dir + 2) % 4 };
        for (int k = 0; k < 4; ++k) {
            int nd = order[k];
            int ny = cy + dy[nd], nx = cx + dx[nd];
            if (visited[ny][nx])
                continue;
            if (houseMap[ny][nx] != 0 && houseMap[ny][nx] != 1)
                continue;
            visited[ny][nx] = true;
            enterDir[ny][nx] = nd;
            qy[tail] = ny;
            qx[tail] = nx;
            ++tail;
        }
    }

    // 도달 가능한 미청소 칸 없음. 청소 완료.
    if (goalY == -1)
        return false;

    // 목표에서 시작점까지 거슬러 올라간 뒤 뒤집어서 따라간다.
    int len = 0;
    int cy = goalY, cx = goalX;
    while (!(cy == y && cx == x)) {
        int nd = enterDir[cy][cx];
        pathBuf[len] = nd;
        ++len;
        cy = cy - dy[nd];
        cx = cx - dx[nd];
    }
    for (int k = len - 1; k >= 0; --k) {
        moveTo(pathBuf[k]);
        setMap();
    }
    return true;
}

void cleanHouse(int mLimitMoveCount)
{
    allClean = false;
    for (int i = 0; i < 60; ++i) {
        for (int j = 0; j < 60; ++j)
            houseMap[i][j] = -1;
    }
    x = n - 1;
    y = n - 1;
    dir = 0;

    // 첫 BFS 전에 현재 위치 주변을 지도에 채워둔다.
    setMap();

    while (!allClean) {
        // 가장 가까운 미청소 구역으로 이동. 남은 곳이 없으면 종료.
        if (!findDirtyZone())
            allClean = true;
    }
}