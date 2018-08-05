/// 15714.열려라 참깨

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector <int> x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	x.resize(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	bool flag = 0;
	int hall;
	cin >> hall;
	x[0] -= hall;
	flag = x[0] < 0;
	for (int i = 1; i < n; i++) {
		int hall;
		cin >> hall;


	}

}

/*
1,000,000

LCA?



*/