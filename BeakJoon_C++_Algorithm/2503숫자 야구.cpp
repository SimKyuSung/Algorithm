/// 2503숫자 야구

#include <iostream>
#include <vector>

using namespace std;

vector <bool> pos;

void init();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	int n, ans = 0;
	cin >> n;
	while (n--) {
		int num, s, b, r1[3], counter = 0;
		cin >> num >> s >> b;
		
		while (num) {
			r1[counter++] = num % 10;
			num /= 10;
		}

		for (int x = 100; x < 999; x++) {
			if (pos[x]) {
				int tmp = x, r2[3], counter = 0;
				int ss = 0, bb = 0;
				while (tmp) {
					r2[counter++] = tmp % 10;
					tmp /= 10;
				}
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (r1[i] == r2[j]) {
							if (i == j) ss++;
							else		bb++;
						}
					}
				}
				if (ss != s || bb != b)
					pos[x] = false;
			}
		}
	}

	for (int i = 100; i < 999; i++) {
		if (pos[i])
			ans++;
	}
	cout << ans;
}

void init() {
	pos.resize(1000, true);
	for (int i = 0; i < 111; i++)
		pos[i] = false;
	for (int i = 0; i < 1000; i++) {
		int tmp = i;
		int r[3], counter = 0;
		while (tmp) {
			int x = tmp % 10;
			if (x == 0) 		pos[i] = false;
			for (int j = 0; j < counter; j++)
				if (r[j] == x)	pos[i] = false;
			r[counter++] = x;
			tmp /= 10;
		}
	}
}