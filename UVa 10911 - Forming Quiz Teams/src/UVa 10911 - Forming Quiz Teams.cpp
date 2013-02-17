#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

double memo[(1 << 16)];
int n, x[10], y[10];

double dist(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double pairup(int mask) {
	if (mask == (1 << n) - 1)
		return 0;
	if (memo[mask] != 0)
		return memo[mask];

	double ans = 2e9;
	int p1, p2;

	for (p1 = 0; p1 < n; p1++) {
		if (!(1 & (mask >> p1)))
			break;
	}
	for (p2 = p1 + 1; p2 < n; p2++) {
		if (!(1 & (mask >> p2))) {
			ans = min(ans, dist(p1, p2) + pairup(mask | (1 << p1) | (1 << p2)));
		}
	}

	return memo[mask] = ans;
}

int main() {
	char s[21];
	int count = 0;

	while (scanf("%d", &n), n) {
		count++;
		n *= 2;
		for (int i = 0; i < n; i++) {
			scanf("%s %d %d", s, &x[i], &y[i]);
		}

		memset(memo, 0, sizeof(memo));
		double ans = pairup(0);

		printf("Case %d: %.2lf\n", count, ans);
	}

	return 0;
}
