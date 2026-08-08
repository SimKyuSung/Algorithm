/// 4435중간계 전쟁

#include <iostream>

using namespace std;

int a[6] = { 1, 2, 3 ,3, 4, 10 };
int b[7] = { 1, 2, 2, 2, 3, 5, 10 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;
		
		int g = 0, e = 0, input;
		for (int i = 0; i < 6; i++) {
			cin >> input;
			g += a[i] * input;
		}
		for (int i = 0; i < 7; i++) {
			cin >> input;
			e += b[i] * input;
		}
		if (g > e) ans = 1;
		else if (g < e) ans = -1;

		cout << "Battle " << tc;
		if (ans == -1) cout << ": Evil eradicates all trace of Good\n";
		else if (ans == 1) cout << ": Good triumphs over Evil\n";
		else cout << ": No victor on this battle field\n";
	}

}