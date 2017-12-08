/// 4811알약

#include <iostream>

using namespace std;

size_t a[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 31; i++)
		a[0][i] = 1;
	for (int i = 1; i < 31; i++)
		for (int j = i; j < 31; j++)
			a[i][j] = a[i - 1][j] + a[i][j - 1];

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << a[n][n] << "\n";
	}
}

/*
약의 개수 N

2진 트리 경우의 수


*/