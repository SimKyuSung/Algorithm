/// 14659한조서열정리하고옴ㅋㅋ

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 한조 머기중
vector <int> hanzo;

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin >> n;

	hanzo.resize(n);

	int killRating, potg = 0;

	for (int i = 0; i < n; i++)
		cin >> hanzo[i];

	for (int i = 0; i < n; i++) {
		killRating = 0;
		for (int j = i + 1; j < n; j++) {
			if (hanzo[i] >= hanzo[j])	killRating++;
			else						break;
		}
		potg = max(potg, killRating);
	}
	cout << potg;
}

/*

4 2 3 1 5 7

4 2 3 1 

6 4 10 2 5 7 11


*/