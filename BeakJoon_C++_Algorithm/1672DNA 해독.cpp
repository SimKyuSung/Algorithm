/// 1672DNA ÇØµ¶

#include <iostream>
#include <string>

using namespace std;

string dna;
char mapping[4][4] = { 'A', 'C', 'A', 'G', 'C', 'G', 'T', 'A', 'A', 'T', 'C', 'G', 'G', 'A', 'G', 'T' };
int alp[100];

int main()
{
	ios::sync_with_stdio(false);
	alp['A'] = 0;
	alp['G'] = 1;
	alp['C'] = 2;
	alp['T'] = 3;

	int n;	cin >> n;
	dna.resize(n);
	cin >> dna;

	for (int i = n - 1; i > 0; i--)
		dna[i - 1] = mapping[alp[dna[i - 1]]][alp[dna[i]]];
	cout << dna[0];
}