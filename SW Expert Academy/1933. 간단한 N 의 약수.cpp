/// 1933. 간단한 N 의 약수

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			cout << i << ' ';
	}
}

/*

소수 Array를 만드는 방법도 있으니 귀찮으니 생략

*/