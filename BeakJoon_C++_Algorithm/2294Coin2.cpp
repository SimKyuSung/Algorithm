#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXX = 10004;

vector <int> coinCount(MAXX, MAXX);
vector <int> coin;

int main()
{
	ios::sync_with_stdio(false);

	// n가지 동전, k원
	int n, k, input;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input;
		coin.push_back(input);
	}

	// 동전 가치 sort
	sort(coin.begin(), coin.end());
	for (int i = 0; i < n; i++)
		coinCount[coin[i]] = 1;

	// 가장 적게 쓰는 방법을 체택
	for (int i = coin[0] + 1; i < MAXX; i++) {
		for (int c = 0; c < n; c++)
			if (i - coin[c] > 0)
				coinCount[i] = min(coinCount[i], coinCount[i - coin[c]]);
		if (coinCount[i] != MAXX)
			coinCount[i]++;
		for (int c = 1; c < n; c++)
			coinCount[coin[c]] = 1;
	}

	if (coinCount[k] != MAXX)
		printf("%d\n", coinCount[k]);
	else
		printf("-1\n");
}

/*
* 최소값을 가져와야 한다.
* 최대값으로 초기화를 하고
* coin의 가치를 뺀것 들과 비교하여 작은 값을 가져온다.

*/