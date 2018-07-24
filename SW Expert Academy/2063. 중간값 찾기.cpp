/// 2063. 중간값 찾기

#include <iostream>
#include <algorithm>

using namespace std;

int arr[200];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	cout << arr[n / 2] << '\n';

}