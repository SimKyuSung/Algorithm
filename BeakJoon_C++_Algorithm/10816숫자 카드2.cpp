/// 10816숫자 카드2

#include <iostream>

using namespace std;

int a[20000001];

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, num;
	cin >> n;
	while (n--) {
		cin >> num;
		a[num + 10000000]++;
	}
	cin >> n;
	while (n--) {
		cin >> num;
		cout << a[num + 10000000] << " ";
	}

}