/// 15740.A+B - 9

#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define endl '\n'

using namespace std;

const long long LIM = 1e9;

queue <int> bigNumQ(string str, bool flag) {
	int num = 0;
	int negative = 1;
	if (flag) 
		negative = -1;

	queue <int> q;
	long long ten = 1;
	while (!str.empty()) {
		if (ten == LIM) {
			q.push(num * negative);
			ten = 1;
			num = 0;
		}
		if (str.back() != '-')
			num += (str.back() - '0') * ten;
		str.pop_back();
		ten *= 10;
	}
	q.push(num * negative);
	return q;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string strA, strB;
	bool flag;
	cin >> strA >> strB;

	bool na = 0, nb = 0;
	if (strA[0] == '-') {
		na = 1;
		strA = strA.substr(1);
	}
	if (strB[0] == '-') {
		nb = 1;
		strB = strB.substr(1);
	}
	queue<int> qa = bigNumQ(strA, na);
	queue<int> qb = bigNumQ(strB, nb);

	bool negative = 0, counter = 0;
	if (strA.size() != strB.size())

	int c = 0;

	stack <int> ans;
	while (!qa.empty() || !qb.empty()) {
		int a = 0, b = 0;
		if (!qa.empty()) {
			a = qa.front();
			qa.pop();
		}
		if (!qb.empty()) {
			b = qb.front();
			qb.pop();
		}
		//cout << a << " + " << b << endl;
		int num = a + b + c;
		c = 0;

		if (num <= -LIM) {
			num += LIM;
			c = -1;
		}
		else if (num >= LIM) {
			num -= LIM;
			c = 1;
		}
		ans.push(num);
	}
	if (c)
		ans.push(c);

	while (!ans.empty() && ans.top() == 0)
		ans.pop();

	if (ans.empty())
		ans.push(0);
	cout << ans.top();

	//if (ans.top() < 0)
	//	negative = 1;

	ans.pop();
	while (!ans.empty()) {
		int x = ans.top();
		ans.pop();

		if (negative && x > 0)
			x -= LIM;
		if (!negative && x < 0)
			x += LIM;

		if (x < 0)
			x = -x;
		cout.fill('0');
		cout.width(9);
		cout << x;
	}
}