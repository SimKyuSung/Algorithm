/// 2075.N번째 큰 수

#include <iostream>
#include <queue>
#include <memory.h>

#define endl '\n'

using namespace std;

//priority_queue <int> pq;

struct PriorityQueue {
	int a[1505];
	int size;
	PriorityQueue() {
		memset(a, 0, sizeof(a));
		size = 1;
	}

	void push(int input) {
		int i = size / 2, j = size++;
		a[j] = input;
		while (a[i] > a[j]) {
			a[i] ^= a[j];
			a[j] ^= a[i];
			a[i] ^= a[j];
			i >>= 1;
			j >>= 1;
		}
	}
	void pop() {
		int i = 1;
		a[i] = a[size - 1];
		a[size - 1] = 0;

		int left = i * 2;
		int right = left + 1;
		while (a[i] > a[left] || a[i] > a[right]) {
			if (a[left] == 0)
				break;
			else if (a[left] < a[right]) {
				a[i] ^= a[left];
				a[left] ^= a[i];
				a[i] ^= a[left];
				i = left;
			}
			else {
				a[i] ^= a[right];
				a[right] ^= a[i];
				a[i] ^= a[right];
				i = right;
			}
			left = i * 2;
			right = left + 1;
		}
		size--;
	}
	int top() {
		return a[1];
	}
};

PriorityQueue pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}

	for (int i = n; i < n * n; i++) {
		cin >> a;
		//pq.pop();
		pq.push(a);
		pq.pop();
	}
	cout << pq.top() << endl;
}

/*

pop() 위치에 따른 틀린 TC
3
7 4 1
8 5 2
9 6 3

*/