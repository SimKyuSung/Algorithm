// 2605Resort

#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	list<int> order;
	list<int>::iterator itor;
	int n, input;
	cin >> n;
	cin >> input;
	order.push_back(1);
	for (int i = 2; i <= n; i++) {
		int index = 1;
		cin >> input;
		if (input) {
			for (itor = order.end(); itor != order.begin(); itor--, index++) {
				if (index == input)
					break;
			}
			order.insert(--itor, i);
		}
		else
			order.push_back(i);
	}
	for (itor = order.begin(); itor != order.end(); itor++)
		printf("%d ", *itor);
	printf("\n");

}

/*
5
0 1 1 3 2
*/