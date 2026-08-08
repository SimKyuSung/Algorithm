/// 2986.ÆÄ½ºÄ®

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

// sqrt(10^9) ~= 31622.776601...
const int MAX = 31623;
bool prime[31623];
vector <int> ps;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) {
			ps.push_back(i);
			for (int j = i + i; j < MAX; j += i)
				prime[j] = 1;
		}
	}

	int n, x = 1;
	cin >> n;
	for (int i = 0; i < ps.size() && ps[i] < n; i++) {
		if (n % ps[i] == 0) {
			x = n / ps[i];
			break;
		}
	}
	cout << n - x << endl;
}
/*
int counter = 0, n;
cin >> n;
for (int i = n - 1; i > 0; i--) {
	counter++;
	if (n % i == 0)
		break;
}
cout << counter << endl;


*/