/// 11286Àý´ë°ª Èü

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

priority_queue< pair <int, bool> > pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				int tmp = 1;
				if (pq.top().second) tmp = -1;
				cout << -pq.top().first * tmp << "\n";
				pq.pop();
			}
		}
		else	pq.push({ -abs(x), x < 0 });
	}
}