/// 5297Å°·ÎÄ¿

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string line, left;
		stack <char> right;
		cin >> line;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '<') {
				if (!left.empty()) {
					right.push(left.back());
					left.pop_back();
				}
			}
			else if (line[i] == '>') {
				if (!right.empty()) {
					left.push_back(right.top());
					right.pop();
				}
			}
			else if (line[i] == '-') {
				if (!left.empty())
					left.pop_back();
			}
			else
				left.push_back(line[i]);

		}
		while (!right.empty()) {
			left.push_back(right.top());
			right.pop();
		}
		if (!left.empty())
			cout << left << endl;
	}

}