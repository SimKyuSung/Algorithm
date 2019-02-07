/// 14488.준오는 급식충이야!!

#include <iostream>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

struct s_size_t {
	bool sign;
	size_t val;
};


s_size_t &operator -= (s_size_t &left, const size_t &t) {
	if (left.val < t) {
		left.val = t - left.val;
		left.sign = 1;
		return left;
	}
	left.val -= t;
	return left;
}
s_size_t &operator += (s_size_t &right, const size_t &t) {
	right.val += t;
	return right;
}

bool operator <= (const s_size_t &a, const s_size_t &b) {
	if (a.sign ^ b.sign)
		return a.sign;
	if (a.sign & b.sign) {
		return a.val >= b.val;
	}
	return a.val <= b.val;
}

s_size_t max(const s_size_t a, const s_size_t b) {
	if (a.sign ^ b.sign) {
		if (a.sign)
			return b;
		else
			return a;
	}
	if (a.sign & b.sign) {
		if (a.val < b.val)
			return a;
		return b;
	}
	if (a.val < b.val)
		return b;
	return a;
}

s_size_t min(const s_size_t a, const s_size_t b) {
	if (a.sign ^ b.sign) {
		if (a.sign)
			return a;
		else
			return b;
	}
	if (a.sign & b.sign) {
		if (a.val < b.val)
			return b;
		return a;
	}
	if (a.val < b.val)
		return a;
	return b;
}


struct Student {
	s_size_t left, right;
};

vector <Student> student;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	size_t t = 0, a;
	string strT;
	cin >> n >> strT;

	int i = 0;
	while (i < strT.size() && strT[i] != '.') {
		t *= 10;
		t += strT[i++] - '0';
	}

	t *= 10000;
	if (strT[i] == '.') {
		strT += "0000";
		t += 1000 * (strT[i + 1] - '0');
		t += 100 * (strT[i + 2] - '0');
		t += 10 * (strT[i + 3] - '0');
		t += 1 * (strT[i + 4] - '0');
	}

	student.resize(n);
	for (i = 0; i < n; i++) {
		cin >> student[i].left.val;
		student[i].left.val *= 10000;
		student[i].right.val = student[i].left.val;
	}
	for (i = 0; i < n; i++) {
		cin >> a;
		a *= t;
		student[i].left -= a;
		student[i].right += a;
	}

	s_size_t left, right;
	right.val = (unsigned long long)-1;
	left.val = right.val;
	left.sign = 1;
	right.sign = 0;

	for (auto s : student) {
		left = max(left, s.left);
		right = min(right, s.right);
	}
	cout << (left <= right) << endl;
}