/// 10610_30

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> counter(10, 0);

int main()
{
	ios::sync_with_stdio(false);
	bool ans = true;
	string num;	cin >> num;
	
	for (int i = 0; i < num.length(); i++)	counter[num[i] - '0']++;
	int a = 0;
	for (int i = 1; i < 10; i++)	a += counter[i];
	if (a == 0 || counter[0] == 0)	ans = false;
	else {
		int th = 0;
		for (int i = 1; i < 9; i++) th += counter[i] * i;
		th %= 3;
		// 나머지가 있을경우 현재 숫자는 3의 배수가 안된다. ㅠㅠ
		if (th)			ans = false;
	}
	if (ans)
		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < counter[i]; j++)
				printf("%d", i);
	else 	printf("-1");
}