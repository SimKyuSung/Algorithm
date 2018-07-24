/// 1961. 숫자 배열 회전

#include <iostream>

#define endl '\n'

using namespace std;

int arr[7][7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		cout << '#' << t << endl;
		for (int i = 0; i < n; i++) {
			// 90
			for (int j = n - 1; j >= 0; j--)
				cout << arr[j][i];
			cout << ' ';
			// 180
			for (int j = n - 1; j >= 0; j--)
				cout << arr[n - 1 - i][j];
			cout << ' ';
			// 270
			for (int j = 0; j < n; j++)
				cout << arr[j][n - 1 - i];
			cout << endl;
		}
	}
}