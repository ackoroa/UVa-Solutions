#include <cstdio>
#include <algorithm>

int main() {
	int ages[2000000];
	int n;

	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			scanf("%d", &ages[i]);
		}

		std::sort(ages, ages + n);

		for (int i = 0; i < n; i++) {
			printf("%d", ages[i]);
			if(i!=n-1)printf(" ");
		}
		printf("\n");
	}

	return 0;
}
