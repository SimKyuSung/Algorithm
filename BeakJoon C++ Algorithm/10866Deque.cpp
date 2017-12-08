// 10866Deque

#include <iostream>
#include <cstdio>
#include <string>
#include <deque>>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;	cin >> n;
	deque <int> dq;
	while (n--) {
		int input;
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> input;
			dq.push_front(input);
		}
		else if (cmd == "push_back") {
			cin >> input;
			dq.push_back(input);
		}
		else if (cmd == "pop_front") {
			if (!dq.empty()) {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
			else	printf("-1\n");
		}
		else if (cmd == "pop_back") {
			if (!dq.empty()) {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
			else	printf("-1\n");
		}
		else if (cmd == "size") printf("%d\n", dq.size());
		else if (cmd == "empty") {
			if (dq.empty())	printf("1\n");
			else			printf("0\n");
		}
		else if (cmd == "front") {
			if (!dq.empty())	printf("%d\n", dq.front());
			else				printf("-1\n");
		}
		else if (cmd == "back") {
			if (!dq.empty()) 	printf("%d\n", dq.back());
			else				printf("-1\n");
		}
	}
}

