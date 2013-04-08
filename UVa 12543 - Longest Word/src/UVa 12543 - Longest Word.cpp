#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
	int prev = -1, cur;
	char s[10010] = "", tmp[10010];
	char ans[10010] = "";
	int anslen = 0;

	while (scanf("%s", tmp) != EOF) {
		strcat(s, tmp);
		strcat(s, " ");
	}

	int len = strlen(s);
	for (cur = 0; cur < len; cur++) {
		if (s[cur] == 'E' && s[cur + 1] == '-' && s[cur + 2] == 'N'
				&& s[cur + 3] == '-' && s[cur + 4] == 'D')
			break;

		if (!(isalpha(s[cur]) || s[cur] == '-')) {
			s[cur] = 0;
			if (cur - prev - 1 > anslen) {
				anslen = cur - prev - 1;
				strcpy(ans, s + prev + 1);
			}
			prev = cur;
		}
	}

	for (int i = 0; i < anslen; i++) {
		printf("%c", tolower(ans[i]));
	}
	printf("\n");

	return 0;
}
