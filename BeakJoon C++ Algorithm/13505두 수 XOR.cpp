/// 13505두 수 XOR

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector < bitset<32> > a;

class Trie {
public:
	// left, right 2진 트리 (0, 1)
	Trie *next[2];
	int now = 0;
	Trie() {
		next[0] = NULL;
		next[1] = NULL;
	}
	void insert(bitset<32> a, int counter) {
		now = a[counter];
		if (counter == 0) return;
		
		int nextNode = a[counter - 1];
		if (!next[nextNode])
			next[nextNode] = new Trie;
		next[nextNode]->insert(a, counter - 1);
	}
	int query(bitset<32> a, int counter) {
		// 내가 트리상에 존재 함으로 NULL값은 걱정 하지 않는다.
		if (counter == 0) return 0;
		
		int nextNode = !a[counter - 1];
		if (next[nextNode]) {
			return next[nextNode]->query(a, counter - 1) + (1 << counter - 1);
		}
		else 
			return next[!nextNode]->query(a, counter - 1);
	}
};

Trie root;

int main()
{
	int n, ans = 0, tmp;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[i] = tmp;
		root.insert(a[i], 31);
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, root.query(a[i], 31));
	cout << ans << '\n';
}