/// 2105. [모의 SW 역량테스트] 디저트 카페

#include <iostream>
#include <algorithm>
#include <bitset>
#include <memory.h>

#define endl '\n'

using namespace std;


// LD, RD, LU, RU
int dx[] = { -1, 1, -1, 1 };
int dy[] = { 1, 1, -1, -1 };

int cafe[20][20];

bitset<100> dp[20][20];
bool check[20][20];

int n;
void a(int ,int);
int b(int, int);
int leftCounter, rightCounter;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int ans = 0, digitNum;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cafe[i][j];
				cafe[i][j]--;
			}
		}
		
		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				/*for (int t = 0; t < n; t++)
					for (int k = 0; k < n; k++)
						dp[t][k] = 0;*/
				memset(dp, 0, sizeof(dp));
				memset(check, 0, sizeof(check));

				leftCounter = min(j, n - i - 2);
				rightCounter = min(n - j - 1, n - i - 2);
				a(i, j);
				ans = max(ans, b(i, j));
				/*cout << "ans: ";
				cout << ans << '\t';*/
			}
			//cout << endl;
		}
		
		cout << '#' << t << ' ' << (ans == 0 ? -1 : ans * 2) << endl;
	}
}

void a(int y, int x) {
	//cout << "start point: ";
	//cout << y << ' ' << x << '\n';
	bitset<100> sum1(0);
	sum1[cafe[y][x]] = 1;

	//cout << "a: ";
	// 왼쪽 아래
	int ny = y, nx = x;
	for (int i = 0; i < leftCounter; i++) {
		ny++;
		nx--;
		if (sum1[cafe[ny][nx]])
			break;
		sum1[cafe[ny][nx]] = 1;

		// 오른쪽 아래
		int nny = ny, nnx = nx;
		bitset<100> sum2 = sum1;
		for (int j = 0; j < rightCounter; j++) {
			nny++;
			nnx++;
			if (nny >= n)
				break;
			//cout << nny << ' ' << nnx << '\t';
			if (sum2[cafe[nny][nnx]])
				break;
			dp[nny][nnx] = sum2;
			sum2[cafe[nny][nnx]] = 1;
			check[nny][nnx] = 1;
			//cout << nny << ' ' << nnx << '\t';
			
		}
	}
	//cout << endl;
}
int b(int y, int x) {
	int ans = 0;
	bitset<100> sum2(0);
	//cout << "b: ";
	// 오른쪽 아래
	int nny = y, nnx = x;
	for (int j = 0; j < rightCounter; j++) {
		nny++;
		nnx++;
		if (sum2[cafe[nny][nnx]])
			break;
		sum2[cafe[nny][nnx]] = 1;
		// 왼쪽 아래
		int ny = nny, nx = nnx;
		bitset<100> sum1 = sum2;
		for (int i = 0; i < leftCounter; i++) {
			ny++;
			nx--;
			if (ny >= n)
				break;
			if (sum1[cafe[ny][nx]])
				break;
			sum1[cafe[ny][nx]] = 1;
			if (check[ny][nx] && ((sum1 & dp[ny][nx]) == 0)) {
				ans = max(ans, i + j + 2);
				//cout << ny << ' ' << nx << '\t';
				//cout << i << ' ' << j << '\t';
			}
		}
	}
	//cout << endl;
	return ans;
}

/*

n * n 에서 최대로 가능한수
n = 20;

[3]		4
[4]		6
[5]		8
[6]		10

6 * 6
X T X T X T
T X T X T X
X T X T X T
T X T X T X
X T X T X T
T X T X T X

Y 에서 가능한 경우의 수 t
	T
  Y T T
T T t t T
T T t t T
  T t t
    T

	X X
  X X X X
X X X X X X
  X X X X
    X X

X t x t x T
T x t x t X
X t x t x T
T x t x t X
X T X T X T
T X T X T X

[400]	798


*/