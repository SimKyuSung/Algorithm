/// 15708.미네크래프트

#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

typedef long long ll;

priority_queue <int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, t, p, k, sum;
	cin >> n >> t >> p;
	sum = -p;
	while (n--) {
		cin >> k;
		if (sum + p + k <= t) {
			sum += k;
			ans.push(k);
		}
		else if (!ans.empty() && ans.top() > k) {
			sum -= ans.top();
			ans.pop();
			sum += k;
			ans.push(k);
		}
		sum += p;
	}
	cout << ans.size() << endl;
}

/*

최대 시간: 17
이동 시간: 1

	3		5		2		6		9		1
	0		p		2p		3p		4p		5p
	3		6		4		9		13		6		
	3
					3+4 = 7
			5		x		7		11		4
											7+4
			5		x		6		9		x

	pq 2개


	t = 11
	3		5		2		6		9		1
	3		9		12
	3		4		7		8		9		11

*/