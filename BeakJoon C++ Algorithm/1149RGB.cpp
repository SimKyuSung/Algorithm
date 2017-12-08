#include <iostream>
#define MIN(A, B) ((A > B) ? B : A)

using namespace std;

int N;
int RGB[3][1000];
int cost[3][1000];		// dpTable

int cc(int, int);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> RGB[0][i] >> RGB[1][i] >> RGB[2][i];
		cost[0][i] = -1;
		cost[1][i] = -1;
		cost[2][i] = -1;
	}
	// 처음이 빨강일때 초록일때 파랑일때를 생각한다.
	for (int i = 0; i < 3; i++)
		cc(i, 0);
	
	int ans = cost[0][0];
	if (ans > cost[1][0])
		ans = cost[1][0];
	if (ans > cost[2][0])
		ans = cost[2][0];

	cout << ans << endl;
}

int cc(int rgb, int n) {
	if (n == N) return 0;

	if (cost[rgb][n] > 0)
		return cost[rgb][n];
	cost[rgb][n] = RGB[rgb][n];

	if (rgb == 0)
		cost[rgb][n] += MIN(cc(1, n + 1), cc(2, n + 1));
	if (rgb == 1)
		cost[rgb][n] += MIN(cc(0, n + 1), cc(2, n + 1));
	if (rgb == 2)
		cost[rgb][n] += MIN(cc(0, n + 1), cc(1, n + 1));

	return cost[rgb][n];
}