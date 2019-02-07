/// 15740.A+B - 9

#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

const long long LIM = 1e9;

queue <int> bigNumQ(string &str, bool flag) {
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
	int c = 0;

	vector <int> ans;
	while (!qa.empty() || !qb.empty() || c != 0) {
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
		ans.push_back(num);
	}
	
	//for (int i = ans.size() - 1; i >= 0; i--)
	//	cout << ans[i];
	//cout << endl;

	if (ans.back() < 0) {
		for (int i = 0; i < ans.size() - 1; i++) {
			if (ans[i] > 0) {
				ans[i] -= LIM;
				ans[i + 1] += 1;
			}
		}
	}
	else {
		for (int i = 0; i < ans.size() - 1; i++) {
			if (ans[i] < 0) {
				ans[i] += LIM;
				ans[i + 1] -= 1;
			}
		}
	}

	while (!ans.empty() && ans.back() == 0)
		ans.pop_back();

	for (int i = 0; i < int(ans.size() - 1); i++) {
		if (ans[i] < 0)
			ans[i] *= -1;
	}

	if (ans.empty())
		ans.push_back(0);
	cout << ans.back();
	
	for (int i = ans.size() - 2; i >= 0; i--) {
		cout.fill('0');
		cout.width(9);
		cout << ans[i];
	}
	cout << endl;



}


/*

열정
창의력
협력
도전
정직

*/