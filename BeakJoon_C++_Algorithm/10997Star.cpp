#include <iostream>
#include <string>

using namespace std;

int N;

string star[1024];

void starMaker(int);


int main()
{
	cin >> N;
	N = N * 4 - 1;
	star[1] = "*****";
	star[2] = "*";
	star[3] = "* ***";
	star[4] = "* * *";
	star[5] = "* * *";
	star[6] = "*   *";
	star[7] = "*****";

	if (N == 3)
		cout << "*\n";
	else {
		if (N > 7)
			starMaker(11);
		for (int i = 1; i <= N; ++i)
			cout << star[i] << endl;
	}
	return 0;
}

void starMaker(int n) {

	// 복사하기
	for (int i = n; i > 0; i--)
		star[i + 2] = star[i];

	// 1번줄
	for (int i = 0; i < 4; i++)
		star[1] += "*";
	// 2번줄
	star[2] = "*";

	// 복사 구간
	// 앞에 두줄 복사 구간
	star[3] = "* " + star[3];
	star[3] += "**";
	for (int i = 1; i < n - 6; i++)
		star[4] += " ";
	for (int i = 4; i < n + 1; i++)
		star[i] = "* " + star[i] + " *";

	// n + 1번 줄
	star[n - 1] = "*";
	for (int i = 2; i < n - 2; i++)
		star[n - 1] += " ";
	star[n - 1] += "*";

	// n번 줄
	star[n] = star[1];
	if (n == N)
		return;
	else
		starMaker(n + 4);
}

/*
1
1

2
7-5

3
11-9

4
15-13


*/