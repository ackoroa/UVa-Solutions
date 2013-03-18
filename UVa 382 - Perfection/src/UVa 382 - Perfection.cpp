#include <cstdio>
using namespace std;

int main() {
	int n;
	int sum;
	bool ab;

	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &n), n) {
		ab = false;
		sum = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0)
				sum += i;
			if (sum > n) {
				ab = true;
				break;
			}
		}

		printf("%5d  ", n);
		if (ab)
			printf("ABUNDANT\n");
		else if (sum == n)
			printf("PERFECT\n");
		else
			printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}
