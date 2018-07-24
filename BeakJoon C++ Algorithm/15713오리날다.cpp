/// 15713��������

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define fi first
#define se second

using namespace std;

typedef pair<long long, int> LI;
const long long INF = 1e15;

// ����, ��������
vector <LI> yh;
// -(���� ���� + ������ �Ÿ�), -���� ����
priority_queue <LI> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	yh.resize(n);
	for (int i = 0; i < n; i++)
		cin >> yh[i].first >> yh[i].second;
	sort(yh.begin(), yh.end());
	
	int i = 0;
	pq.push({ 0,0 });
	long long ans = INF;
	while (i < n) {
		// ���̰� ���ڶ� ������ ���̱�
		while (!pq.empty() && -pq.top().second < yh[i].first)
			pq.pop();
		if (pq.empty())
			break;

		// ���� ȿ������ ���� ����
		long long distance = pq.top().first + yh[i].first;
		int level = yh[i].first + yh[i].second;
		
		if (level < s)	pq.push({ distance - yh[i].second - level, -level });
		else			ans = min(ans, -distance + s - yh[i].first);
		i++;
	}
	if (ans != INF)	cout << ans << '\n';
	else			cout << "Ducks can't fly\n";
}