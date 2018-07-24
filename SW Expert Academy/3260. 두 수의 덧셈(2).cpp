/// 3260. µÎ ¼öÀÇ µ¡¼À(2)

#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define endl '\n'

using namespace std;

const long long LIM = 1e9;

queue <int> bigNumQ(string str) {
	int num = 0;
	queue <int> q;
	long long ten = 1;
	while (!str.empty()) {
		if (ten == LIM) {
			q.push(num);
			ten = 1;
			num = 0;
		}
		num += (str.back() - '0') * ten;
		str.pop_back();
		ten *= 10;
	}
	q.push(num);
	return q;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		string strA, strB;
		cin >> strA >> strB;
		queue<int> qa = bigNumQ(strA);
		queue<int> qb = bigNumQ(strB);

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
			int num = a + b + c;
			ans.push(num % LIM);
			c = num >= LIM;
		}
		if (c)
			ans.push(c);
		cout << '#' << t << ' ';
		cout << ans.top();
		ans.pop();
		while (!ans.empty()) {
			cout.fill('0');
			cout.width(9);
			cout << ans.top();
			ans.pop();
		}
		cout << endl;
	}

}