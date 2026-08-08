/// 10102°³Ç¥

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, a = 0;
	string line;
	cin >> v >> line;
	for (int i = 0; i < v; i++) {
		if (line[i] == 'A') a++;
		else				a--;
	}

	if (a > 0)		cout << "A";
	else if (a < 0)	cout << "B";
	else			cout << "Tie";
}