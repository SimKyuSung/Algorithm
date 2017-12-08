/// 4803Ʈ��

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, a, b, tc = 1;
	while (1) {
		cin >> n >> m;
		if (n == 0)	break;
		
		vector < vector<int> > edge(n);
		vector <bool> ch(n, false);
	

		while (m--) {
			cin >> a >> b;
			edge[a - 1].push_back(b - 1);
			edge[b - 1].push_back(a - 1);
		}

		// node, root
		queue <pair <int, int> > q;
		int t = 0;

		for (int i = 0; i < n; i++) {
			// 1. üũ ���� �ʾҴٸ� q�� �ֱ�
			if (!ch[i]) {
				ch[i] = true;
				q.push({ i, -1 });
				t++;
				bool cycle = false;
				while (!q.empty()) {
					int node = q.front().first;
					int root = q.front().second;
					q.pop();
					// 2. queue�� �� ����� �ڽ� ���� ���
					for (int nextNode : edge[node]) {
						// 3. �̹� �湮�� ���
						if (ch[nextNode]) {
							// 4. ���� ��Ʈ�� �ƴ϶�� -> ����Ŭ�� ����...
							if (root != nextNode)
								cycle = true;
						}
						else {
							ch[nextNode] = true;
							q.push({ nextNode, node });
						}
					}
				}
				if (cycle)	t--;
			}
		}
		cout << "Case " << tc++;
		
		if (t == 0)			cout << ": No trees.\n";
		else if (t == 1)	cout << ": There is one tree.\n";
		else				cout << ": A forest of " << t << " trees.\n";
	}
}