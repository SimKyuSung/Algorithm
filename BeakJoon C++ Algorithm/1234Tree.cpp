#include <iostream>
#include <memory.h>

using namespace std;

long long dpTable[11][101][101][101];
int combination[11][11];
int combina(int, int);
long long solve(int, int, int, int);

int main()
{
	int	N, R, G, B;
	memset(dpTable, -1, sizeof(dpTable));	// 1����Ʈ ������ 0xff�� �ʱ�ȭ
	cin >> N >> R >> G >> B;
	cout << solve(N, R, G, B) << endl;
}


long long solve(int n, int r, int g, int b) {
	long long &ref = dpTable[n][r][g][b];
	if (ref != -1) return ref;
	if (n == 0) return 1;
	int temp;
	ref = 0;
	
	// 1������ ä�ﶧ, n�� 1�� ��� -> 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10
	if (r >= n) ref += solve(n - 1, r - n, g, b);
	if (g >= n) ref += solve(n - 1, r, g - n, b);
	if (b >= n) ref += solve(n - 1, r, g, b - n);

	// 2������ ä�ﶧ, n�� 2�� ��� -> 2, 4, 6, 8, 10
	if (n % 2 == 0) {
		// ��ġ ������ 2* temp C temp 
		temp = n / 2;
		if (r >= temp && g >= temp)
			ref += solve(n - 1, r - temp, g - temp, b) * combina(2 * temp, temp);
		if (r >= temp && b >= temp)
			ref += solve(n - 1, r - temp, g, b - temp) * combina(2 * temp, temp);
		if (g >= temp && b >= temp)
			ref += solve(n - 1, r, g - temp, b - temp) * combina(2 * temp, temp);
	}
	
	// 3������ ä�ﶧ, n�� 3�� ��� -> 3, 6, 9
	if (n % 3 == 0) {
		// ��ġ ������ (3 * temp C tmep) * (2 * temp C temp) 
		temp = n / 3;
		if (r >= temp && g >= temp && b >= temp)
			ref += solve(n - 1, r - temp, g - temp, b - temp) * combina(3 * temp, temp) * combina(2 * temp, temp);
	}
	return ref;
}

int combina(int n, int k) {
	int &ref = combination[n][k];
	if (ref != 0)	return ref;
	if (k == 1)	return n;
	if (k == n) return 1;
	ref = combina(n - 1, k - 1) + combina(n - 1, k);
	return ref;
}