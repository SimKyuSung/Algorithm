// 1302Best

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	vector<string> book;
	vector<int> bestSeller(1004, 1);
	// input
	int n;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		book.push_back(name);
	}

	// sort and count
	sort(book.begin(), book.end());
	int key = 0;
	for (int i = 1; i < n; i++) {
		if (book[i] == book[i - 1])
			bestSeller[key]++;
		else
			key = i;
	}
	// max_element		-> ������ �ִ밪�� iterator �� ��ȯ, (*max_element �� �ϸ� ���� ��ȯ)
	// distance(a, b)	-> a �� b ���� �Ÿ��� ��ȯ
	cout << book[distance(bestSeller.begin(), max_element(bestSeller.begin(), bestSeller.end()))] << endl;
}