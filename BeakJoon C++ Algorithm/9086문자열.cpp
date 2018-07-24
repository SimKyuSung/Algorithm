/// 9086¹®ÀÚ¿­

#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	while (n--) {
		std::string s;
		std::cin >> s;
		std::cout << s.front() << s.back() << '\n';
	}
}