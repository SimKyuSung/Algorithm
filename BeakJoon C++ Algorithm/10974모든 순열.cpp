/// 10974모든 순열

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

// b를 a 자리에 삽입 하고 b를 삭제 (a < b)
inline void swap1(int a, int b) {
	list <int>::iterator itor1 = arr.begin();
	list <int>::iterator itor2 = arr.begin();
	advance(itor1, a);
	advance(itor2, b);
	arr.insert(itor1, *itor2);
	arr.erase(itor2);
}
// b에 a를 삽입하고 a를 삭제(a < b)
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
// 순열 알고리즘
/*
0. 종료조건
1. 스왑 안하고 그냥 출력
2. 스왑하고 재귀
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
