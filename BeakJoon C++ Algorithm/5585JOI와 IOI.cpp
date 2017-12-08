/// 5585JOI¿Í IOI

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	string ioi = "IOI";
	string joi = "JOI";
	int ic = 0, jc = 0;
	cin >> line;
	for (int i = 0; i < line.length() - 2; i++) {
		// ioi
		int io = 1, jo = 1;
		for (int j = 0; j < 3; j++) {
			if (ioi[j] != line[i + j])
				io = 0;
			if (joi[j] != line[i + j])
				jo = 0;
		}
		ic += io;
		jc += jo;
	}
	cout << jc << endl << ic << endl;
}