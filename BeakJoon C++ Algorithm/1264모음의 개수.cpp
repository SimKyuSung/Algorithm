/// 1264모음의 개수

#include <cstdio>
#include <iostream>

using namespace std;

char vowel[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

int getLine_C(char*);
int counter(char*);

int main()
{
	char str[300];
	while (getLine_C(str))
		printf("%d\n", counter(str));
}

int getLine_C(char *str) {
	int i = 0;
	str[i] = getchar();
	if (str[i] == '#')
		return 0;

	while (str[i] != '\n')
		str[++i] = getchar();

	return 1;
}

int counter(char *str) {
	int i = 0;
	int ret = 0;
	while (str[i] != '\n') {
		for (int j = 0; j < 10; j++)
			if (str[i] == vowel[j])
				ret++;
		i++;
	}
	return ret;
}