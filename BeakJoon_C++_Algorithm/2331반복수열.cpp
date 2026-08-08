/// 2331반복수열

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector <int> d;

int main()
{
	ios::sync_with_stdio(false);
	
	long long a, p;	cin >> a >> p;
	d.push_back(a);
	while (1) {
		long long next = 0;
		a = d.back();
		while (a) {
			next += pow(a % 10, p);
			a /= 10;
		}
		for (int i = 0; i < d.size(); i++) {
			if (d[i] == next) {
				cout << i << endl;
				return 0;
			}
		}
		d.push_back(next);
	}
}