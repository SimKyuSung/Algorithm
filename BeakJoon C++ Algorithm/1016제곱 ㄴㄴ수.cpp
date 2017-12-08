/// 1016제곱 ㄴㄴ수

#include <iostream>
#include <vector>

using namespace std;

const int maximum = 1000000;
vector <size_t> prime;
bool check[maximum + 1];

int main()
{
	// 소수 감별
	check[0] = true;
	check[1] = true;
	for (size_t i = 2; i <= maximum; i++) {
		if (!check[i]) {
			prime.push_back(i * i);
			for (int j = i; j <= maximum; j += i)
				check[j] = true;
		}
	}
	size_t left, right;
	cin >> left >> right;

	
	for (size_t p : prime) {
		if (p > right)	break;
		// left - right 에서 p의 배수가 처음으로 출몰 하는곳
		// p * x >= left 일때 p * x의 최솟값 (x는 양의 정수)
		// left + p - left % p
		size_t num = left + p - left % p;
		if (left % p == 0) num = left;
		while (num <= right) {
			check[num - left] = false;
			num += p;
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= right - left; i++) {
		if (check[i]) {
			cout << i + left << endl;
			ans++;
		}
	}
	cout << ans << endl;
}

/*

제곱수					(0	~	1,000,000)
4 9 16 25 36 49 64 ...		1,000,000,000,000

소수 제곱수				(2	~	
4 9 25 49 121

최악의 경우의 수
1,000,000,000,000	~	1,000,001,000,000

1. 
 4  8  12 16 20
		9	  18
         13
 13 % 4 = 1
 13 + 4 - 1 = 16
 13 % 9 = 4
 13 + 9 - 4

*/