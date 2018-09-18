/// 2621.카드게임

#include <iostream>

#define endl '\n'
#define MAX(a, b) (a)>(b)?(a):(b)

using namespace std;

struct Count {
	int card, maxNum;
}counter[128];
int numCount[10];

int score(int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 5, maxNum = 0;
	while (n--) {
		char card;
		int num;
		cin >> card >> num;
		counter[card].card++;
		counter[card].maxNum = MAX(counter[card].maxNum, num);
		numCount[num]++;
		maxNum = MAX(maxNum, num);
	}
	cout << score(maxNum) << endl;
	return 0;
}
 
int score(int maxNum) {
	bool straight = 1;
	int threeOfaKind = 0, twoPair = 0;

	int n = 5, tmp = maxNum;
	while (n--) {
		if (!numCount[tmp--])
			straight = 0;
	}

	counter[0] = counter['R'];
	counter[1] = counter['B'];
	counter[2] = counter['Y'];
	counter[3] = counter['G'];

	for (int i = 9; i > 0; i--) {
		// 2
		if (numCount[i] == 4)
			return i + 800;
		if (numCount[i] == 3)
			threeOfaKind = i;
		if (numCount[i] == 2) {
			twoPair *= 10;
			twoPair += i;
		}
	}
	// 3
	if (threeOfaKind && twoPair)
		return threeOfaKind * 10 + twoPair + 700;

	for (int i = 0; i < 4; i++) {
		// 1, 4
		if (counter[i].card == 5)
			return counter[i].maxNum + 600 + 300 * straight;
	}
	// 5
	if (straight)
		return maxNum + 500;
	// 6
	if (threeOfaKind)
		return threeOfaKind + 400;
	// 7, 8
	if (twoPair) {
		if (twoPair > 10)
			twoPair += 100;
		return twoPair + 200;
	}
	// 9
	return maxNum + 100;
}