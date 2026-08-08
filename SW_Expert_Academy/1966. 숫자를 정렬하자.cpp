/// 1966. 숫자를 정렬하자

#include <iostream>
#include <algorithm>

using namespace std;

int arr[50];

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
			cin >> arr[i];

		sort(arr, arr + n);

		cout << '#' << t;
		for (int i = 0; i < n; i++)
			cout << ' ' <<arr[i];
		cout << '\n';
	}
}