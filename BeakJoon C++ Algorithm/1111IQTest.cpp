#include <iostream>
#include <cstdio>

using namespace std;

int seq[50];

int main()
{
	// input
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	// algorithm
	double a, b;
	int ans;


	// output

}

/*
dp[i + 1] = dp[i] * a + b

a(n + 1) = p * a(n) + b

a(n + 1) + q = p * (a(n) + q)
a(n + 1) = p * a(n) + pq - q
q(p - 1) = b;

a(n + 1) + q = p^(n - 1) * (a(1) + q)



*/

