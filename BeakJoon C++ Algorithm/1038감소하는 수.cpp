/// 1038감소하는 수

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int dpTable[1000001];

int main()
{
	int n;

	cin >> n;
	if (n < 10) {
		cout << n;
		return 0;
	}
	if (n == 1022) {
		cout << 9876543210;
		return 0;
	}
	if (n > 1022) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < 10; i++)	dpTable[i] = i;
	int counter = 9;
	long long i = 10;
	while (counter != n) {
		long long k = i;
		long long cy = 1;
		bool pos = true;
		while (k / 10) {
			int kk = k / 10;
			if (kk % 10 <= k % 10) {
				pos = false;
				i += pow(10, cy - 1);
				//cout << "break"<< cy << endl;
				break;
			}
			cy++;
			k /= 10;
		}
		if (pos) {
			counter++;
			//cout << counter << "\t" << i << endl;
			i++;
		}
	}
	cout << i - 1;
}
/*

규칙성 찾기

자리수 > 맨 앞자리 + 1

*/