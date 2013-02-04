#include <cstdio>
using namespace std;

int f[20], c[20];

int main() {
	int n, tc, v, t, count = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &f[i], &c[i]);
	}

	scanf("%d", &tc);
	while (tc--) {
		count++;
		scanf("%d %d", &v, &t);

		int minc = 10000000, tf, tcost;
		for (int s = 0; s < (1 << n); s++) {
			tf = tcost = 0;
			for (int i = 0; i < n; i++) {
				if (1 & (s >> i)) {
					tf += f[i];
					tcost += c[i];
				}
			}
			if (tf * t >= v) {
				if (tcost < minc) {
					minc = tcost;
				}
			}
		}

		if (minc < 10000000)
			printf("Case %d: %d\n", count, minc);
		else
			printf("Case %d: IMPOSSIBLE\n", count);
	}

	return 0;
}
