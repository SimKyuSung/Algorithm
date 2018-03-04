/// 10173니모를 찾아서

#include <iostream>
#include <string>

using namespace std;

string upper(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > 'Z')
			s[i] += 'A' - 'a';
	}
	return s;
}

int main()
{
	while (1) {
		string line;
		getline(cin, line);
		if (line == "EOI")
			break;
		line = upper(line);
		if (line.find("NEMO") != string::npos)
			cout << "Found\n";
		else
			cout << "Missing\n";
	}
}