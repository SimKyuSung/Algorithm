#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	// N 이 1일때
	for (int i = 1; i < N; i++)
		cout << " ";
	cout << "*\n";

	// N 이 2이상 부터
	// 10990
	/*for (int i = 2; i <= N; i++) {
		for (int j = i; j < N; j++)
			cout << " ";
		cout << "*";
		for (int j = 1; j < (i - 1) * 2; j++)
			cout << " ";
		cout << "*\n";
	}*/
	// 10991
	/*for (int i = 2; i <= N; i++) {
		for (int j = i; j < N; j++)
			cout << " ";
		for (int j = 0; j <= (i - 1) * 2; j++)
			if (j % 2)
				cout << " ";
			else
				cout << "*";
		cout << endl;
	}*/
	// 10992
	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j++)
			cout << " ";
		cout << "*";
		for (int j = 1; j < (i - 1) * 2; j++)
			cout << " ";
		cout << "*\n";
	}
	if (N != 1) {
		for (int i = 0; i <= (N - 1) * 2; i++)
			cout << "*";
		cout << endl;
	}

}