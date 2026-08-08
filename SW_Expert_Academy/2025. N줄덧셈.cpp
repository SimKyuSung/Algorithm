/// 2025. N¡Ÿµ°º¿

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << (n + 1) * n / 2;
}

/*
overflow πÊ¡ˆ ±‚π˝

(A + B) / 2
(B - A + 2A) / 2
(B - A) / 2 + A

*/