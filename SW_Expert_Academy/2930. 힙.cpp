/// 2930. 힙

#include <iostream>
#include <algorithm>
#include <memory.h>

#define endl '\n'

using namespace std;

int heap[200003];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {
		int n, cmd, x, index = 1;
		memset(heap, 0, sizeof(heap));
		heap[0] = (unsigned)-1 >> 1;
		cin >> n;
		cout << '#' << t;
		while (n--) {
			cin >> cmd;
			if (cmd == 1) {
				cin >> x;
				// 삽입: 맨뒤에 넣고 위로 올라오면서 바꾸기
				heap[index] = x;
				int now = index, next = index >> 1;
				while (heap[now] > heap[next]) {
					swap(heap[now], heap[next]);
					now = next;
					next >>= 1;
				}
				index++;
			}
			else {
				if (index == 1)
					cout << ' ' << -1;
				else {
					// 삭제: 맨뒤에 친구를 맨위로 올리고 둘중 큰거랑 교환
					cout << ' ' << heap[1];
					heap[1] = 0;
					index--;
					swap(heap[1], heap[index]);
					int now = 1, left = 2, right = 3;
					while (heap[now] < heap[left] || heap[now] < heap[right]) {
						if (heap[right] < heap[left]) {
							swap(heap[now], heap[left]);
							now = left;
						}
						else {
							swap(heap[now], heap[right]);
							now = right;
						}
						left = now << 1;
						right = left + 1;
					}
				}
			}
		}
		cout << endl;
	}
}

/*
			1
		2		3
	4	5		6		7
8	9	10 11	12 13	14	15

	  1
	2	3
4	5	6	7
*/