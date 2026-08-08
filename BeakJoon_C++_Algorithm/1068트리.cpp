/// 1068Tree

#include <iostream>
#include <vector>

using namespace std;

vector <int> tree[50];

int leafCounter(int, int);

int main()
{
	int n;	cin >> n;
	int node;
	int rootNode;

	for (int i = 0; i < n; i++) {
		cin >> node;
		if (node == -1) {
			rootNode = i;
			continue;
		}
		tree[node].push_back(i);
	}
	int x;	cin >> x;
	if (x == rootNode) {
		cout << 0;
		return 0;
	}
	cout << leafCounter(rootNode, x);
}


int leafCounter(int node, int x) {
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == x) {
			tree[node].erase(tree[node].begin() + i);
			break;
		}
	}
	if (tree[node].size() == 0)	return 1;
	else {
		int counter = 0;
		for (int i = 0; i < tree[node].size(); i++)
			counter += leafCounter(tree[node][i], x);
		return counter;
	}
}