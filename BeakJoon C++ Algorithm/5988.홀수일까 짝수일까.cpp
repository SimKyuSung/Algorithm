/// 5988.Ȧ���ϱ� ¦���ϱ�

#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string i;
		cin >> i;
		cout << ((i.back() % 2) ? "odd" : "even") << endl;
	}
}