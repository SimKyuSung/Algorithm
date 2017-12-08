#include <iostream>
#include <stack>

using namespace std;

int N;
int graphMap[1001][1001];
int out[1001];
void getEulerCircuit(int, stack<int>&);
int ending;
bool outing;

int main()
{

	cin >> N;
	int edgeCounter = 0;
	stack<int> s;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graphMap[i][j];
			out[i] += graphMap[i][j];
		}
		if (out[i] % 2)
			outing = true;
	}

	// 1번 인덱스에서 시작
	getEulerCircuit(1, s);

	// 만약 지워지지 않은 간선이 있다면 탈락
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			edgeCounter += graphMap[i][j];

	//cout << edgeCounter << endl;
	
	if (outing || edgeCounter > 0 || ending != 1) {
		cout << -1 << endl;
		return 0;
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

}


void getEulerCircuit(int here, stack<int> &circuit) {
	for (int there = 1; there <= N; there++) {
		while (graphMap[here][there] > 0) {
			graphMap[here][there]--;
			graphMap[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	ending = here;
	circuit.push(here);
}