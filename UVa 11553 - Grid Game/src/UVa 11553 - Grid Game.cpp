#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t, n, grid[8][8];
	int i, j;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &grid[i][j]);
			}
		}

		int choice[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int minimum = 10000000;
		do {
			int sum = 0;
			for (i = 0; i < n; i++) {
				sum += grid[i][choice[i]];
			}
			minimum = min(sum, minimum);
		} while (next_permutation(choice, choice + n));

		printf("%d\n", minimum);
	}

	return 0;
}
