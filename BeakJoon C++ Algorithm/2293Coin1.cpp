/// 2293Coin1

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> coin;
vector <int> money(10004, 0);

int main()
{
	// input
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	money[0] = 1;
	for (int i = 0, input; i < n; i++) {
		cin >> input;
		coin.push_back(input);
		/*
		for (int j = coin[i]; j <= k; j++) {
			money[j] += money[j - coin[i]];
			printf("dpTable[%d] = %d\n", j, money[j]);
		}
		cout << endl;
		*/
	}

	// 모든 방법을 채택, 소수구하기 알고리즘(아리토네스의 체)를 중복 실행
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			money[j] += money[j - coin[i]];
			//printf("dpTable[%d] = %d\n", j, money[j]);
		}
		//cout << endl;
	}
	cout << money[k];
}


/*

3 10
1
2
5

1 : 1		1
2 : 2		1	+[1]
3 : 2		1
4 : 3		1	
5 : 4		1	
6 : 5		1	+[4]
7 : 6		1
8 : 7		1	+[6]
9 : 8		1
10 : 10		1



*/