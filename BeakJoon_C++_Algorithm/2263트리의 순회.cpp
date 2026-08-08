/// 2263트리의 순회

#include <iostream>
#include <vector>

using namespace std;

vector <int> inorder;
vector <int> postorder;

// left, right, node
void preorder(int, int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, tmp;
	cin >> n;
	inorder.resize(n + 1);
	postorder.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		inorder[tmp] = i;
	}
	for (int i = 0; i < n; i++)	cin >> postorder[i];
	preorder(0, n, 0, n);
}

void preorder(int i_left, int i_right, int p_left, int p_right) {
	// inoder에서 node를 찾아내어 left right로 나눔

	int root = postorder[p_right - 1];
	cout << root << " ";
	int index = inorder[root];

	if (i_left != index)		preorder(i_left, index, p_left, p_left + index - i_left);
	if (index + 1 != i_right)	preorder(index + 1, i_right, p_left + index - i_left, p_right - 1);
}

/*
in order
left - root - right
2
1 3

post order
left - right - root
3
1 2

pre order
root - left - right
1
2 3

*/