/// 3260. 두 수의 덧셈

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

const long long LIM = 1e9;

class BigNum {
	BigNum *next;
public:
	int num;
	BigNum(string);
	BigNum(int, BigNum, BigNum);
	BigNum(int, BigNum);
	BigNum(int);

	void print();

	BigNum operator+(BigNum &);
	friend ostream& operator<<(ostream&, const BigNum&);
};

BigNum::BigNum(string strA) {
	num = 0;
	next = NULL;
	for (long long ten = 1; ten < LIM && !strA.empty(); ten *= 10) {
		num += (strA.back() - '0') * ten;
		strA.pop_back();
	}
	if (strA.size() > 0)
		next = new BigNum(strA);
}

BigNum BigNum::operator+(BigNum &ref) {
	if (next != NULL && ref.next != NULL)
		return BigNum(num + ref.num, *next, *ref.next);
	else if (next != NULL)
		return BigNum(num + ref.num, *next);
	else if (ref.next != NULL)
		return BigNum(num + ref.num, *ref.next);
	else
		return BigNum(num + ref.num);
}
BigNum::BigNum(int n, BigNum a, BigNum b) {
	num = n % LIM;
	next = NULL;
	bool carry = n >= LIM;
	
	// 8가지 경우의 수 
	n = a.num + b.num + carry;
	if (a.next != NULL && b.next != NULL) {
		next = new BigNum(n, *a.next, *b.next);
	}
	else if (a.next != NULL) {
		next = new BigNum(n, *a.next);
	}
	else if (b.next != NULL) {
		next = new BigNum(n, *b.next);
	}
	else if (n)
		next = new BigNum(n);
}
BigNum::BigNum(int n, BigNum a) {
	num = n % LIM;
	next = NULL;
	bool carry = n >= LIM;

	// 4가지 경우의수
	n = a.num + carry;
	if (a.next != NULL)
		next = new BigNum(n, *a.next);
	else if (n)
		next = new BigNum(n);
}
BigNum::BigNum(int n) {
	num = n % LIM;
	next = NULL;
	if (n >= LIM)
		next = new BigNum(1);
}
void BigNum::print() {
	if (next != NULL) {
		next->print();
		cout.fill('0');
		cout.width(9);
	}
	cout << num;
}
ostream& operator<<(ostream& output, const BigNum& a) {
	if (a.next != NULL) {
		cout << *a.next;
		cout.fill('0');
		cout.width(9);
	}
	output << a.num;
	return output;
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
		BigNum a(strA), b(strB);
		BigNum c = a + b;
		cout << '#' << t << ' ' << c << endl;
	}
}