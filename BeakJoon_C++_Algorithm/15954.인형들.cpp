/// 15954.인형들
/// B번 - 인형들

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl '\n'

using namespace std;

vector <double> doll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	doll.resize(n);
	for (int i = 0; i < n; i++)
		cin >> doll[i];

	double ans = 1e15;

	while (k <= n) {
		double sum = 0;
		for (int i = 0; i < k; i++)
			sum += doll[i];
		for (int i = 0; i <= n - k; i++) {
			double m = sum / k;
			double vrn = 0;
			for (int j = 0; j < k; j++) {
				vrn += pow((doll[j + i] - m), 2);
			}
			vrn /= k;
			double stdDev = sqrt(vrn);
			ans = min(ans, stdDev);
			sum -= doll[i];
			sum += doll[i + k];
		}
		k++;
	}

	//cout << fixed;
	cout.precision(11);
	cout << ans << endl;
}