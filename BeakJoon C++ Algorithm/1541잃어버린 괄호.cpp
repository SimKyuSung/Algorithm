/// 1541�Ҿ���� ��ȣ

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0, a;
	char op;
	bool f = false;

	cin >> ans;
	while (cin >> op >> a) {

	if (op == '-') f = true;

	if (f)	ans -= a;
	else	ans += a;
	}
	cout << ans << endl;

	//// �Ľ� �ؼ� �غ���
	//int a[51] = { 0, }, counter = 0;
	//char op[51];
	//bool f = false;
	//string s;

	//cin >> s;

	//// 1. ����, ���� �Ľ�
	//for (int i = 0; i < s.length(); i++) {
	//	if (s[i] == '-' || s[i] == '+') {
	//		counter++;
	//		op[counter] = s[i];
	//	}
	//	else {
	//		a[counter] *= 10;
	//		a[counter] += (s[i] - '0');
	//	}
	//}

	//// 2. ���
	//for (int i = 1; i <= counter; i++) {
	//	if (op[i] == '-') f = true;
	//	if (f)	a[0] -= a[i];
	//	else	a[0] += a[i];
	//}
	//cout << a[0] << endl;
}