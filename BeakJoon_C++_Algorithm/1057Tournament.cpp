#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	// N명이 참가하는 토너먼트 라운드
	// n1과 n2가 최초로 만나는 라운드는?
	ios::sync_with_stdio(false);
	int N, n1, n2;
	cin >> N >> n1 >> n2;
	n1++;
	n2++;
	// log2(10^5) = 5 * log2(10) ~= 20
	for (int i = 1; i < 20; i++) {
		n1 = n1 / 2 + 1;
		n2 = n2 / 2 + 1;
		if (n1 == n2) {
			printf("%d\n", i);
			break;
		}
	}

}