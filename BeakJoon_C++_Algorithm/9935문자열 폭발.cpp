/// 9935문자열 폭발

#include <iostream>
#include <string>
#include <stack>

using namespace std;

char ans[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line, c4;
	cin >> line >> c4;
	int n = line.length(), m = c4.length();
	
	int counter = 0, j = 0;
	stack <int> index;
	for (int i = 0; i < n; i++, j++) {
		ans[j] = line[i];
		if (c4[counter] == line[i]) {
			counter++;
			if (counter == m) {
				j -= m;
				if (!index.empty()) {
					counter = index.top();
					index.pop();
				}
				else counter = 0;
			}
		}
		else {
			index.push(counter);
			if (counter) {
				counter = 0;
				i--;
				j--;
			}
		}
		//cout << ans << endl;
	}
	//cout << j << endl;
	ans[j] = 0;
	if (j)		cout << ans << "\n";
	else		cout << "FRULA\n";
}

/*

mirkovC4nizCC44
mirCk4ovC4nizCC44
C4

mirkovniz
mirCk4ovniz

*/