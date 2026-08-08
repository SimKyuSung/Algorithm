/// 13698Hawk eyes

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cup[4] = { 1, 2 ,3, 4 };
	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		switch (line[i]) {
		case 'A':
			swap(cup[0], cup[1]);
			break;
		case 'B':
			swap(cup[0], cup[2]);
			break;
		case 'C':
			swap(cup[0], cup[3]);
			break;
		case 'D':
			swap(cup[1], cup[2]);
			break;
		case 'E':
			swap(cup[1], cup[3]);
			break;
		case 'F':
			swap(cup[2], cup[3]);
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < 4; i++)
		if (cup[i] == 1)
			cout << i + 1 << endl;
	for (int i = 0; i < 4; i++)
		if (cup[i] == 4)
			cout << i + 1 << endl;
}