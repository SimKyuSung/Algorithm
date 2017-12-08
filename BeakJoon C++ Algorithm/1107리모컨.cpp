/// 1107리모컨

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool btn[10];
vector <int> channel;
vector <int> cipher;

int main()
{
	int n, m;	cin >> n >> m;

	for (int i = 0; i < 10; i++)
		btn[i] = true;
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		btn[input] = false;
	}

	// 근접한 모든 경우의 수를 만들어 본다.
	channel.push_back(100);
	cipher.push_back(0);

	if (btn[0]) {
		channel.push_back(0);
		cipher.push_back(1);
	}
	for (int i = 1; i < 999900; i++) {
		int tmp = i;
		int c = 0;
		bool pos = true;

		while (tmp > 0) {
			if (!btn[tmp % 10]) {
				pos = false;
				break;
			}
			tmp /= 10;
			c++;
		}
		
		if (pos) {
			channel.push_back(i);
			cipher.push_back(c);
		}
	}

	int ans = 1000000;
	for (int i = 0; i < channel.size(); i++) {
		//cout << channel[i] << endl;
		int counter;
		if (n < channel[i])
			counter = cipher[i] + (channel[i] - n);
		else
			counter = cipher[i] + (n - channel[i]);
		ans = min(ans, counter);
	}
	cout << ans << endl;
	return 0;
}

/*
500000 - 499900

666666 - 6 + 166666
777777 - 6 + 277777
888888 - 6 + 388888
999999 - 6 + 499999

 뭐지.. 체점 서버 맛탱이감

*/