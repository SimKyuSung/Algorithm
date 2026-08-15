/// 2025. N줄덧셈

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << (n + 1) * n / 2;
}

/*
overflow 방지 기법

(A + B) / 2
(B - A + 2A) / 2
(B - A) / 2 + A

*/