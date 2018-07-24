/// 2050. 알파벳을 숫자로 변환

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] - 'A' + 1 << ' ';

}