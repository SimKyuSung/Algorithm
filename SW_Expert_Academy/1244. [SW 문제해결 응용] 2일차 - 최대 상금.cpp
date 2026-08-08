/// 1244. [S/W 문제해결 응용] 2일차 - 최대 상금

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector <int>, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int num, c;
		vector <int> arr;
		cin >> num >> c;
		while (num) {
			arr.push_back(num % 10);
			num /= 10;
		}
		

		if (arr.size() <= c) {
			sort(arr.begin(), arr.end());
			num = 0;
			for (int i = arr.size() - 1; i >= 0; i--) {
				num *= 10;
				num += arr[i];
			}
			cout << '#' << t << ' ' << num << '\n';
		}
		else {
			cout << '#' << t << ' ' << solve(arr, c) << '\n';
		}
	}
}

int solve(vector <int> arr, int c) {
	if (c == 0) {
		int ret = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			ret *= 10;
			ret += arr[i];
		}
		return ret;
	}
	int ret = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			swap(arr[i], arr[j]);
			ret = max(ret, solve(arr, c - 1));
			swap(arr[i], arr[j]);
		}
	}
	return ret;
}

/*

최악의 경우의 수
612345

321 3
123 2
213	1
123 0

512346
412356
312456
213456
	4
123456	5





*/