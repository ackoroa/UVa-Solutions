#include <cstdio>
#include <cctype>
using namespace std;

int main() {
	char c;
	while (scanf("%c", &c) != EOF) {
		int count = 0;
		while (true) {
			if (c == '\n') {
				break;
			} else if (isalpha(c)) {
				while (isalpha(c)) {
					scanf("%c", &c);
				}
				count++;
			} else {
				scanf("%c", &c);
			}
		}
		printf("%d\n",count);
	}

	return 0;
}
