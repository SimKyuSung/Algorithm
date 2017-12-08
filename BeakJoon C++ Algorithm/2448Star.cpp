#include <iostream>
#include <string>

using namespace std;

string star[3072];
int N;
void makeStar(int);

int main()
{
	cin >> N;
	star[0] = "  *  ";
	star[1] = " * * ";
	star[2] = "*****";

	makeStar(3);
	for (int i = 0; i < N; i++)
		cout << star[i] << endl;
}

void makeStar(int n) {
	if (n == N * 2)
		return;
	if (n == 3) {
		makeStar(n * 2);
		return;
	}
	string temp = "";
	for (int i = 0; i < n / 2; i++)
		temp += " ";
	for (int i = n / 2; i < n; i++)
		star[i] = star[i - n / 2] + " " + star[i - n / 2];

	for (int i = 0; i < n / 2; i++)
		star[i] = temp + star[i] + temp;
	makeStar(n * 2);
}