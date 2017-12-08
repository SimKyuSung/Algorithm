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

	// n���� ����, k��
	int n, k, input;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input;
		coin.push_back(input);
	}

	// ���� ��ġ sort
	sort(coin.begin(), coin.end());
	for (int i = 0; i < n; i++)
		coinCount[coin[i]] = 1;

	// ���� ���� ���� ����� ü��
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
* �ּҰ��� �����;� �Ѵ�.
* �ִ밪���� �ʱ�ȭ�� �ϰ�
* coin�� ��ġ�� ���� ��� ���Ͽ� ���� ���� �����´�.

*/