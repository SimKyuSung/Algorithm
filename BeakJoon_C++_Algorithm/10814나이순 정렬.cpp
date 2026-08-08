/// 10814나이순 정렬

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector<string>> names(201, vector<string>(0));

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		names[age].push_back(name);
	}
	for (int i = 1; i <= 200; i++)
		for (int j = 0; j < names[i].size(); j++)
			cout << i << " " << names[i][j] << "\n";
}

/*
1 * 2 = 2
2 * 1 = 2
3 * 1 = 3


*/