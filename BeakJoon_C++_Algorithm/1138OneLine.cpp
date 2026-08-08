/// 1138OneLine

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n;		cin >> n;
	
	int tall[11];
	int line[11];
	int insert;

	for (int i = n - 1; i >= 0; i--)
		cin >> tall[i];
	
	line[0] = n;
	int x = n - 1;
	for (int i = 1; i < n; i++) {
		// 삽입점 찾기
		insert = 0;
		int j = 0;
		while (tall[i] && j <= i) {
			if (line[j] > x) {
				tall[i]--;
				insert++;
			}
			j++;
		}
		// 삽입 하기
		for (j = i + 1; j > insert; j--)
			line[j] = line[j - 1];
		line[insert] = x--;
	}
	

	for (int i = 0; i < n; i++)
		printf("%d ", line[i]);
}
/*

거꾸로 추적한다.

4
4 3
4 2 3
4 2 1 3

*/