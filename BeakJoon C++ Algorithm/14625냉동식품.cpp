/// 14625³Ãµ¿½ÄÇ°

#include <iostream>

using namespace std;

bool check[10];
int num[10] = { 0, };

int main()
{
	int sh, sm;	cin >> sh >> sm;
	int eh, em;	cin >> eh >> em;
	int n;	cin >> n;

	while (sh != eh || sm != em) {
		for (int i = 0; i < 10; i++)
			check[i] = false;
		
		check[sh / 10] = true;
		check[sh % 10] = true;
		check[sm / 10] = true;
		check[sm % 10] = true;

		for (int i = 0; i < 10; i++)
			if (check[i]) num[i]++;

		sm++;
		if (sm >= 60) {
			sm = 0;
			sh++;
		}
	}
	for (int i = 0; i < 10; i++)
		check[i] = false;
	check[sh / 10] = true;
	check[sh % 10] = true;
	check[sm / 10] = true;
	check[sm % 10] = true;
	for (int i = 0; i < 10; i++)
		if (check[i]) num[i]++;
	cout << num[n];
}