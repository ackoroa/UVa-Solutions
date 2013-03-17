#include <cstdio>
using namespace std;

int main() {
	int n, a[101][101];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (i > 0)
				a[i][j] += a[i - 1][j];
			if (j > 0)
				a[i][j] += a[i][j - 1];
			if (i > 0 && j > 0)
				a[i][j] -= a[i - 1][j - 1];
		}
	}

	int ans = -127 * 100 * 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < n; l++) {
					int temp = a[k][l];
					if (i > 0)
						temp -= a[i - 1][l];
					if (j > 0)
						temp -= a[k][j - 1];
					if (i > 0 && j > 0)
						temp += a[i - 1][j - 1];

					if (temp > ans)
						ans = temp;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
