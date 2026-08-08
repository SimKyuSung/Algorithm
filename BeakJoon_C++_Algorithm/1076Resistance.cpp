#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map <string, int> resistance;

int main()
{
	resistance.insert({ "black", 0 });
	resistance.insert({ "brown", 1 });
	resistance.insert({ "red", 2 });
	resistance.insert({ "orange", 3 });
	resistance.insert({ "yellow", 4 });
	resistance.insert({ "green", 5 });
	resistance.insert({ "blue", 6 });
	resistance.insert({ "violet", 7 });
	resistance.insert({ "grey", 8 });
	resistance.insert({ "white", 9 });

	ios::sync_with_stdio(false);
	string input[3];

	cin >> input[0];
	cin >> input[1];
	cin >> input[2];


	if (input[0] != "black")
		printf("%d", resistance[input[0]]);
	printf("%d", resistance[input[1]]);
	if (input[0] != "black" || input[1] != "black")
		for (int i = 0; i < resistance[input[2]]; i++)
			printf("0");
	printf("\n");
}