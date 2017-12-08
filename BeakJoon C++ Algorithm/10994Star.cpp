#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;

	for (int i = 0; i < N * 2; ++i) {
		for (int j = 0; j < N; ++j) {
			if (((i + j) % 2) && (j == N - 1))
				continue;
			if ((i + j) % 2)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
	return 0;
}