/// 15662.톱니바퀴 (2)

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

#define endl '\n'

using namespace std;

int t;
vector<bitset<8>> gear;

void gearMove(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	t = 4;
	// 15662.톱니바퀴 (2)
	cin >> t;
	gear.resize(t + 2, 0);
	for (int i = 1; i <= t; i++) {
		string input;
		cin >> input;
		for (int g = 7; g >= 0; g--) {
			gear[i] <<= 1;
			gear[i][0] = (input[g] - '0');
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int i = 0, clock = 0;
		cin >> i >> clock;
		bitset<8> tmpGear = gear[i];
		gearMove(i, clock, -1);
		gear[i] = tmpGear;
		gearMove(i, clock, 1);
		//for (int j = 1; j <= t; j++) {
		//	for (int k = 0; k < 8; k++)
		//		cout << gear[j][k];
		//	cout << endl;
		//}
	}

	int ans = 0;
	for (int i = t; i > 0; i--)
		ans += (gear[i][0]);
	cout << ans << endl;
}

void gearMove(int i, int clock, int d) {
	if (0 < i && i <= t) {
		int now = 4, next = 4;
		now -= 2 * d;
		next += 2 * d;
		if (((gear[i] >> now)[0]) ^ ((gear[i + d] >> next)[0]))
			gearMove(i + d, clock * -1, d);

		if (clock == -1)
			gear[i] = (gear[i] >> 1) | (gear[i] << 7);
		else
			gear[i] = (gear[i] << 1) | (gear[i] >> 7);
	}
}

/*
1번 기어 2
2번 기어 6

2번 기어 2
3번 기어 6

3번 기어 2
4번 기어 6

시계	 방향	=> 오른쪽 시프트
반시계 방향	=> 왼쪽 시프트

[6gear2][6gear2][6gear2][6gear2]

*/