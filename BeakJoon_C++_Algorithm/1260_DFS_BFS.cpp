#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int N, M, V;

int graph[1001][1001];
bool cash1[1001];
bool cash2[1001];

void function1(int);
void function2(int);
queue<int> node;

int main()
{

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}

	// DFS 뿅!
	function1(V);

	// BFS !ㅛㅇ
	cout << endl << V << " ";
	cash2[V] = true;
	function2(V);
	// 큐 비우면서 큐펑션 실행, 
	for (int i = 0; i < N; i++) {
		if (!node.empty()) {
			printf("%d ", node.front());
			function2(node.front());
			node.pop();

		}
		else
			break;
	}
	
	cout << endl;
	// 5초니깐 사랑이다.
	return 0;
}

void function1(int n) {
	// me를 출력 하고 사용함 표시
	printf("%d ", n);
	cash1[n] = true;
	for (int i = 1; i <= N; i++)
		if (graph[n][i] && !cash1[i])
			function1(i);
}

void function2(int n) {
	for (int i = 1; i <= N; i++) {
		// 큐에 넣어 부러~
		if (graph[n][i] && !cash2[i]) {
			node.push(i);
			cash2[i] = true;
		}
	}
}