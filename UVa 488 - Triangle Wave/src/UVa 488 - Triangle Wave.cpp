#include <cstdio>
using namespace std;

int main() {
	int tc, f, a;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d\n%d", &a, &f);

		for (int i = 0; i < f; i++) {
			for (int j = 1; j <= a; j++) {
				for (int k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			for (int j = a - 1; j >= 1; j--) {
				for (int k = 0; k < j; k++) {
					printf("%d", j);
				}
				printf("\n");
			}
			if (i != f - 1)
				printf("\n");
		}
		if (tc)
			printf("\n");
	}

	return 0;
}
