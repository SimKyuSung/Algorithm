// 2108Stats

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arithmetci = 0;
int median;
int mode;
int range;

vector <int> arr;
vector <int> counter(8001, 0);

int main()
{
	// 입력
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int input = 4000;
	//n = 499999;
	while (n--) {
		cin >> input;
		//input = -4000;

		// 산술 평균
		arithmetci += input;
		// 중앙값, 범위
		arr.push_back(input);
		// 최빈값
		counter[input + 4000]++;
	}
	n = arr.size();


	// 알고리즘
	// 0. 정렬
	sort(arr.begin(), arr.end());

	// 1. 산술 평균
	arithmetci = round((double)arithmetci / (double)n);

	// 2. 중 앙 값
	median = arr[n / 2];

	// 3. 최빈값
	int modeCounter = 0;
	bool mulitplex = false;
	for (int i = 0; i < 8001; i++) {
		// 가장 많은 값을 추적
		if (modeCounter <= counter[i]) {
			// 가장 많은 값이 여러개 일 경우 최빈값들중 두번째로 작은 값 출력
			if ((modeCounter == counter[i]) && !mulitplex) {
				mode = i - 4000;
				mulitplex = true;
			}
			if ((modeCounter < counter[i])) {
				mode = i - 4000;
				mulitplex = false;
			}
			modeCounter = counter[i];
		}
	}

	// 4. 범위
	range = arr.back() - arr.front();


	// 출력
	cout << arithmetci << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << range << '\n';
}