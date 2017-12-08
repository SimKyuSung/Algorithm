/// 14467소가 길을 건너간 이유 1

#include <iostream>
#include <vector>

using namespace std;

int cow[11];
int moveCounter = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i < 11; i++)
		cow[i] = -1;

	int n;
	cin >> n;
	while (n--) {
		int cowNum, move;
		cin >> cowNum >> move;
		int &t = cow[cowNum];
		if (t == -1) t = move;
		else if (t != move) {
			t = move;
			moveCounter++;
		}
	}
	cout << moveCounter << endl;
}