/// 14651걷다보니 신천역 삼 (Large)

#include <iostream>

using namespace std;

const long long mod = 1000000009;

long long slideDpTable[3][2];

int main()
{
	int n;	cin >> n;
	// 1 tick
	slideDpTable[0][0] = 0;
	slideDpTable[1][0] = 1;
	slideDpTable[2][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			slideDpTable[j][1] = slideDpTable[0][0] + slideDpTable[1][0] + slideDpTable[2][0];
		for (int j = 0; j < 3; j++)
			slideDpTable[j][0] = slideDpTable[j][1] % mod;
	}
	cout << slideDpTable[0][0] << endl;
}

/*
나머지 정리

1	0
2	12 21
3	102		111		120		201		210		222
4	1002	1011	1020	...

앞자리가 1인 경우 나머지 총합 2
앞자리가 2인 경우 나머지 총합 1

*/