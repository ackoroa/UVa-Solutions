#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char ac[10], bc[10];
	int a[10], b[10];

	while (scanf("%s %s", ac, bc), strcmp(ac, "0") || strcmp(bc, "0")) {
		int nDigitA = strlen(ac);
		int nDigitB = strlen(bc);
		int count = 0;

		for (int i = nDigitA - 1; i >= 0; i--) {
			a[count++] = ac[i] - '0';
		}
		count = 0;
		for (int i = nDigitB - 1; i >= 0; i--) {
			b[count++] = bc[i] - '0';
		}

		count = 0;
		int ans = 0, c = 0;
		while (count < nDigitA && count < nDigitB) {
			c = (a[count] + b[count] + c) / 10;
			if (c)
				ans++;
			count++;
		}
		while (count < nDigitA) {
			c = (a[count] + c) / 10;
			if (c)
				ans++;
			count++;
		}
		while (count < nDigitB) {
			c = (b[count] + c) / 10;
			if (c)
				ans++;
			count++;
		}

		if (ans == 0)
			printf("No ");
		else
			printf("%d ", ans);
		printf("carry operation");
		if (ans > 1)
			printf("s");
		printf(".\n");
	}

	return 0;
}
