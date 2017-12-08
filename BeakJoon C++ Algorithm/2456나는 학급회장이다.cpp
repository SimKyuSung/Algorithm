/// 2456나는 학급회장이다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int can[3][3];

int main()
{
	// input
	int n;	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;	
		for (int c = 0; c < 3; c++) {
			cin >> input;
			can[c][input - 1]++;
		}
	}

	int ans = 0;
	// 비교 분석
	int sum[4];
	for (int i = 0; i < 3; i++)
		sum[i + 1] = can[i][0] + can[i][1] * 2 + can[i][2] * 3;
	sum[0] = max(sum[1], sum[2]);

	if (sum[1] > sum[2] && sum[1] > sum[3])			ans = 1;
	else if (sum[2] > sum[1] && sum[2] > sum[3])	ans = 2;
	else if (sum[3] > sum[2] && sum[3] > sum[1])	ans = 3;
	else {
		// 숫자가 같은놈이 존재 하는경우 3점을 더 많이 먹은 친구가 학교짱이다 (3점도 같고 총점도 같다면 2점도 100% 같다.)
		if (can[0][2] > can[1][2] && can[0][2] > can[2][2])			ans = 1;
		else if (can[1][2] > can[0][2] && can[1][2] > can[2][2])	ans = 2;
		else if (can[2][2] > can[1][2] && can[2][2] > can[0][2])	ans = 3;
	}
	cout << ans << " " << sum[ans] << endl;
}

/*
4
3 2 1
1 2 3
3 2 1
2 3 1

*/