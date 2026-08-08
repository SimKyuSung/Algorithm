/// 11648Áö¼Ó

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, counter = 0;
	cin >> n;
	while (n / 10) {
		int tmp = 1;
		while (n) {
			tmp *= n % 10;
			n /= 10;
		}
		n = tmp;
		counter++;
	}
	cout << counter << endl;
}