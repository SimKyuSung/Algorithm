/// 10974��� ����

#include <iostream>
#include <list>

using namespace std;

int n;
list <int> arr;
inline void swap1(int, int);
inline void swap2(int, int);
inline void print();

void solve(int, int);

int main()
{
	cin >> n;
	list <int>::iterator itor;
	for (int i = 0; i < n; i++)
		arr.push_back(i + 1);
	//for (int i = 0; i < n; i++)
	//	cout << *(cont[i]) << " ";
	//cout << endl;
	solve(0, n);
}

// b�� a �ڸ��� ���� �ϰ� b�� ���� (a < b)
inline void swap1(int a, int b) {
	list <int>::iterator itor1 = arr.begin();
	list <int>::iterator itor2 = arr.begin();
	advance(itor1, a);
	advance(itor2, b);
	arr.insert(itor1, *itor2);
	arr.erase(itor2);
}
// b�� a�� �����ϰ� a�� ����(a < b)
inline void swap2(int a, int b) {
	list <int>::iterator itor1 = arr.begin();
	list <int>::iterator itor2 = arr.begin();
	advance(itor1, a);
	advance(itor2, b);
	itor2++;
	arr.insert(itor2, *itor1);
	arr.erase(itor1);
}

inline void print() {
	list <int>::iterator itor;
	for (itor = arr.begin(); itor != arr.end(); itor++)
		cout << *itor << " ";
	cout << "\n";
}
// ���� �˰���
/*
0. ��������
1. ���� ���ϰ� �׳� ���
2. �����ϰ� ���
*/
void solve(int x, int depth) {
	if (x == depth - 1) {
		print();
		return;
	}
	solve(x + 1, depth);
	for (int i = x + 1; i < n; i++) {
		swap1(x, i);
		solve(x + 1, depth);
		swap2(x, i);
	}
	return;
}
