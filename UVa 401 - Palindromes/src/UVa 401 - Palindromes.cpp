#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

int main() {
	char s[21];
	map<char, char> rev;
	rev['A'] = 'A';
	rev['H'] = 'H';
	rev['I'] = 'I';
	rev['E'] = '3';
	rev['J'] = 'L';
	rev['L'] = 'J';
	rev['M'] = 'M';
	rev['O'] = 'O';
	rev['T'] = 'T';
	rev['U'] = 'U';
	rev['V'] = 'V';
	rev['W'] = 'W';
	rev['X'] = 'X';
	rev['S'] = '2';
	rev['Y'] = 'Y';
	rev['Z'] = '5';
	rev['1'] = '1';
	rev['2'] = 'S';
	rev['3'] = 'E';
	rev['5'] = 'Z';
	rev['8'] = '8';

	while (scanf("%s", s) != EOF) {
		stack<char> checker;
		int len = strlen(s);

		bool palin = true, mirror = true;

		int pos = 0;
		for (; pos < len / 2; pos++) {
			checker.push(s[pos]);
		}
		if (len % 2 != 0) {
			if (!rev.count(s[pos]))
				mirror = false;
			if (rev[s[pos]] != s[pos])
				mirror = false;
			pos++;
		}

		for (; pos < len; pos++) {
			if (checker.top() != s[pos]) {
				palin = false;
			}
			if (!rev.count(checker.top()) || rev[checker.top()] != s[pos]) {
				mirror = false;
			}
			checker.pop();
		}

		printf("%s -- ", s);
		if (palin && mirror)
			printf("is a mirrored palindrome.");
		else if (palin && !mirror)
			printf("is a regular palindrome.");
		else if (!palin && mirror)
			printf("is a mirrored string.");
		else if (!palin && !mirror)
			printf("is not a palindrome.");
		printf("\n\n");
	}

	return 0;
}
