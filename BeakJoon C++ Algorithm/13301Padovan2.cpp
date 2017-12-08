#include <iostream>

using namespace std;

unsigned long long tile[82];

int main()
{
	int n;
	cin >> n;
	tile[0] = 2;
	tile[1] = 4;
	for (int i = 2; i < 81; i++)
		tile[i] = tile[i - 1] + tile[i - 2];
	cout << tile[n] << "\n";
}



/*
tile[0] = 2
tile[1] = 4;
tile[2] = 4 + 2 = 6;
tile[3] = 6 + 4 = 10;
tile[4] = 10 + 6 = 16;
tile[5] = 16 + 10 = 26;
tile[7] = 26 + 16 = 42;
*/