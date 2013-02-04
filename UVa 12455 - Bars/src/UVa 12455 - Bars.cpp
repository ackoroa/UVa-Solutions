#include <cstdio>
using namespace std;

int bar[20];

int main() {
	int tc, target, total, n;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d\n%d", &target, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &bar[i]);
		}

		for (int s = 0; s < (1 << n); s++) {
			total = 0;
			for (int i = 0; i < n; i++) {
				if (1 & (s >> i)) {
					total += bar[i];
				}
			}
			if (total == target)
				break;
		}

		if (total == target)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
