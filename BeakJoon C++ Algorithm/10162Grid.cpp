// 10162Grid

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t, second300, second60, second10;
	cin >> t;
	// 300√ , 60√ , 10√ 
	second300 = t / 300;
	t = t % 300;
	second60 = t / 60;
	t = t % 60;
	second10 = t / 10;
	t = t % 10;
	if (t) {
		printf("-1\n");
		return 0;
	}
	else
		printf("%d %d %d\n", second300, second60, second10);
	return 0;
}