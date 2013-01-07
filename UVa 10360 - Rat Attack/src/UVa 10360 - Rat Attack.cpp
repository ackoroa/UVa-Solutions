#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int TC;
	int d, n, x, y, p;
	int *killed[1024];
	scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &d);
		scanf("%d", &n);
		for (int i = 0; i < 1024; i++) {
			killed[i] = new int[1024];
			for (int j = 0; j < 1024; j++) {
				killed[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &p);
			for (int j = x - d; j <= x + d; j++) {
				if (j < 0 || j >= 1024)
					continue;

				for (int k = y - d; k <= y + d; k++) {
					if (k < 0 || k >= 1024)
						continue;

					killed[j][k] += p;
				}
			}
		}

		int maximum = -1;
		for (int i = 0; i < 1024; i++) {
			for (int j = 0; j < 1024; j++) {
				if (killed[i][j] > maximum) {
					x = i;
					y = j;
					maximum = killed[i][j];
				}
			}
		}

		printf("%d %d %d\n", x, y, maximum);
	}

	return 0;
}
