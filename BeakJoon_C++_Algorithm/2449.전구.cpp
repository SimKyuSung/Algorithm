/// 2449.전구

#include <iostream>
#include <memory.h>
#include <algorithm>

#define endl '\n'

using namespace std;

int n, k;


// 상태 b 부터 시작해서 1 ~ Num중 한가지 색으로 만드는 최소값
// -> 1 ~ num 상태에서 b를 만드는 최소값

//  left - right 구간을 c번으로 만드는 최적값
int dp[200][200][21];
bool check[200][200][21];
int dfs(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(dp, -1, sizeof(dp));
	// 입력
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		// 전구가 1개 일때 x -> x로 바꾸는 경우는 0번 나머지는 1번의 스위칭
		for (int c = 1; c <= k; c++)
			dp[i][i][c] = (c != tmp);
	}

	int ans = 1e9;
	// 모든 전구를 c로 만들 때
	for (int c = 1; c <= k; c++)
		ans = min(ans, dfs(0, n - 1, c));
	cout << ans + 1 << endl;
}


int dfs(int left, int right, int num) {
	int &ret = dp[left][right][num];
	if (ret != -1)	return ret;
	ret = 1e9;

	// 2개 구간합의 최소
	for (int i = left; i < right; i++)
		ret = min(ret, dfs(left, i, num) + dfs(i + 1, right, num));

	// left - right 구간을 다른번호로 바꿈 (스위치 한번 누름)
	if (!check[left][right][num]) {
		check[left][right][num] = 1;
		for (int c = 1; c <= k; c++) {
			if (c != num)
				ret = min(ret, dfs(left, right, c) + 1);
		}
	}

	//cout << left << ' ' << right << ' ' << num <<  ' ' << ret << endl;
	return ret;
}

/*

1 2 3 2 1

0 5 1			0 5 2			0 5 3
1 1 1 1 1		2 2 2 2 2		3 3 3 3 3		
  2 2 2			1	3	1		1 2	  2 1	
	3

2번				3번				4번

*/