#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, K, W;
int techTimeDP[1000];

class tech {
public:
	int id;
	int buildTime;
	int needCount;
	tech *need[1000];

	tech();
	~tech();
	void setData(int);
};

tech building[1000];

tech::tech() {
	id = 0;
	buildTime = 0;
	needCount = 0;
	for (int i = 0; i < 1000; i++) need[i] = NULL;
}
tech::~tech() {
	id = 0;
	buildTime = 0;
	needCount = 0;
	for (int i = 0; i < 1000; i++) need[i] = NULL;
}
void tech::setData(int buildNum) {
	need[needCount++] = &building[buildNum];
}

// algorithm
int techTime(int);

int main()
{
	int T;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {
		int buildNum1, buildNum2;
		int ans;

		// input sequence
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> building[i].buildTime;
			building[i].id = i + 1;
			techTimeDP[i] = -1;
		}
		for (int i = 0; i < K; i++) {
			cin >> buildNum1 >> buildNum2;
			building[buildNum2 - 1].setData(buildNum1 - 1);
		}
		cin >> W;

		// algorithm sequence
		ans = techTime(W);

		// output sequence
		cout << ans << endl;

		// init sequence
		for (int i = 0; i < N; i++)
			building[i].~tech();
	}
}
/*
 * 1. 자신이 필요로 하는 필요조건의 건물들의 최소 건설 타이밍을 구한다.
 * 2. 그중에서 가장 큰값을 가져온다.
*/
int techTime(int w) {
	int ans = 0;
	int x;
	if (techTimeDP[w - 1] != -1)
		return techTimeDP[w - 1];
	for (int i = 0; i < building[w - 1].needCount; i++) {
		x = building[w - 1].need[i]->id;
		ans = max(ans, techTime(x));
	}
	return techTimeDP[w - 1] = ans + building[w - 1].buildTime;
}