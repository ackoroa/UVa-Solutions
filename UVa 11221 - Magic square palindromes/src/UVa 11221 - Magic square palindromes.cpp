#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

char s[50000];

int main() {
	int TC, count = 0;
	scanf("%d", &TC);
	getc(stdin);

	while (TC--) {
		count++;
		char c = ' ';
		int n = 0;
		while (scanf("%c", &c), c != '\n') {
			if (isalpha(c)) {
				s[n++] = c;
			}
		}
		s[n] = '\0';

		bool palin = true;
		if ((sqrt(n) - (int) sqrt(n)) > 0)
			palin = false;
		if (palin) {
			stack<char> checker;
			int i;
			for (i = 0; i < n / 2; i++) {
				checker.push(s[i]);
			}
			if (n % 2 == 1)
				checker.push(s[i]);
			for (; i < n; i++) {
				if (checker.top() != s[i]) {
					palin = false;
					break;
				}
				checker.pop();
			}
		}
		printf("Case #%d:\n", count);
		if (palin)
			printf("%d\n", (int) sqrt(n));
		else
			printf("No magic :(\n");
	}

	return 0;
}
