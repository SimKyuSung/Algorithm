#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int, int);
extern void cleanHouse(int);

#define MAX_N (30)

static int mLimitMoveCnt = 0;
static int houseInfo[MAX_N][MAX_N];
static int isCleaned[MAX_N][MAX_N];
static int robotInfo[3] = { 0, }; // [0] : y, [1] : x, [2] : direction
static int moveRobotsCallCnt = 0;

static int dy[4] = { -1, 0, 1, 0 };
static int dx[4] = { 0, -1, 0, 1 };

static bool ok = false;

void scanFromRobot(int floorState[3][3])
{
    int robot_y = robotInfo[0];
    int robot_x = robotInfo[1];
    int direction = robotInfo[2];
    
    if (direction == 0) // UP
    {
        for (int y = robot_y - 1, sy = 0; y <= robot_y + 1; y++, sy++)
        {
            for (int x = robot_x - 1, sx = 0; x <= robot_x + 1; x++, sx++)
            {
                floorState[sy][sx] = houseInfo[y][x];
            }
        }
    }
    if (direction == 1) // LEFT
    {
        for (int y = robot_y - 1, sx = 2; y <= robot_y + 1; y++, sx--)
        {
            for (int x = robot_x - 1, sy = 0; x <= robot_x + 1; x++, sy++)
            {
                floorState[sy][sx] = houseInfo[y][x];
            }
        }
    }
    else if (direction == 2) // DOWN
    {
        for (int y = robot_y - 1, sy = 2; y <= robot_y + 1; y++, sy--)
        {
            for (int x = robot_x - 1, sx = 2; x <= robot_x + 1; x++, sx--)
            {
                floorState[sy][sx] = houseInfo[y][x];
            }
        }
    }
    else if (direction == 3) // RIGHT
    {
        for (int y = robot_y - 1, sx = 0; y <= robot_y + 1; y++, sx++)
        {
            for (int x = robot_x - 1, sy = 2; x <= robot_x + 1; x++, sy--)
            {
                floorState[sy][sx] = houseInfo[y][x];
            }
        }
    }
}

int moveRobot(int mCommand)
{
    moveRobotsCallCnt++;

    if (mCommand < 0 || mCommand >= 4)
        return 0;

    int next_dir = (robotInfo[2] + mCommand) % 4;

    int sy = robotInfo[0] + dy[next_dir];
    int sx = robotInfo[1] + dx[next_dir];

    if (houseInfo[sy][sx] == 1)
    {
        return 0;
    }
    else
    {
        robotInfo[0] = sy;
        robotInfo[1] = sx;
        robotInfo[2] = next_dir;
        isCleaned[sy][sx] = 1;
    }

    return 1;
}


static bool run()
{
    int N, subTaskCount;

    scanf("%d%d", &N, &subTaskCount);

    init(N, subTaskCount);
    ok = true;

    for (int i = 0; i < subTaskCount; i++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                scanf("%d", &houseInfo[y][x]);
				isCleaned[y][x] = 0;
            }
        }


        scanf("%d %d %d %d", &robotInfo[0], &robotInfo[1], &robotInfo[2], &mLimitMoveCnt);
        isCleaned[robotInfo[0]][robotInfo[1]] = 1;
        moveRobotsCallCnt = 0;
        cleanHouse(mLimitMoveCnt);

        if (mLimitMoveCnt < moveRobotsCallCnt)
            ok = false;
		
		for(int y = 0;y < N;y++)
		{
			for(int x = 0; x < N; x++)
			{
				if(houseInfo[y][x] == 1)
					continue;
				
				if(isCleaned[y][x] == 0)
					ok = false;
			}
		}
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
//    freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
