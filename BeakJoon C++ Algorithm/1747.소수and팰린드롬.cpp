/// 1747.소수&팰린드롬

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MAX = 1003002;
bool p[MAX];
vector <int> x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 2; i < MAX; i++) {
		if (!p[i]) {
			for (int j = i; j < MAX; j += i)
				p[j] = 1;
			int tmp1 = i, tmp2 = 0;
			while (tmp1) {
				tmp2 *= 10;
				tmp2 += tmp1 % 10;
				tmp1 /= 10;
			}
			if (i == tmp2)
				x.push_back(i);
		}
	}
	
	int n;
	cin >> n;
	for (auto x : x) {
		if (x >= n) {
			cout << x << endl;
			break;
		}
	}
}