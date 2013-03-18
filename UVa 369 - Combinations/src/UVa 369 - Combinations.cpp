#include <cstdio>
using namespace std;

long long a[101][101];

int main() {
	int n, m;
	a[1][1] = 1;
	a[1][0] = 1;

	for (int i = 2; i <= 100; i++) {
		a[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	while (scanf("%d%d", &n, &m), n || m) {
		printf("%d things taken %d at a time is %lld exactly.\n", n, m,
				a[n][m]);
	}

	return 0;
}
