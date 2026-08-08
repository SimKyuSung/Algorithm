/// 2502.ถฑ ธิดย ศฃถ๛ภฬ

#include <iostream>

#define endl '\n'

using namespace std;

int counter[31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int d, k;
	cin >> d >> k;
	
	counter[2] = 1;
	counter[3] = 1;
	for (int i = 4; i <= 30; i++)
		counter[i] = counter[i - 1] + counter[i - 2];

	int aCounter = counter[d - 1];
	int bCounter = counter[d];

	int a = 1, b;
	while (1) {
		int x = k - a * aCounter;
		if (x % bCounter == 0) {
			b = x / bCounter;
			break;
		}
		a++;
	}
	cout << a << endl << b << endl;
}

/*

a
b
a + b
a + 2b
2a + 3b
3a + 5b
5a + 8b

*/