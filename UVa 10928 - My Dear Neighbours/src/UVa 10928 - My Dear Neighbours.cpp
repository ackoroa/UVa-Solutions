#include <cstdio>
#include <map>
using namespace std;

int main() {
	map<int, int> out;
	int tc, p, min, cur;
	char s[10001];

	scanf("%d", &tc);
	while (tc--) {
		out.clear();
		scanf("%d\n", &p);
		min = 100000000;
		for (int i = 1; i <= p; i++) {
			gets(s);
			cur = 1;
			for (int j = 0; s[j] != '\0'; j++)
				if (s[j] == ' ')
					cur++;
			out[i] = cur;
			if (cur < min)
				min = cur;
		}

		bool first = true;
		for (int i = 1; i <= p; i++) {
			if (out[i] == min) {
				if (!first)
					printf(" ");

				printf("%d", i);
				first = false;
			}
		}
		printf("\n");
	}
	return 0;
}
