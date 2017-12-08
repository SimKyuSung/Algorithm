/// 2386도비의 영어 공부

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	while (1) {
		char c;	cin >> c;
		if (c == '#')	break;
		string line;
		getline(cin, line);
		int counter = 0;
		for (int i = 0; i < line.length(); i++)
			if (line[i] == c || line[i] == (c - 'a' + 'A')) counter++;
		cout << c << " " << counter << endl;
	}
}