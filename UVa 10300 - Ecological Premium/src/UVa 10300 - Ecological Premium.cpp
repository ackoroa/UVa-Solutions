#include <cstdio>
using namespace std;

int main() {
	int TC, a, n, p, f;

	scanf("%d", &TC);

	while (TC--) {
		int ans = 0;
		scanf("%d", &f);
		for (int i = 0; i < f; i++) {
			scanf("%d %d %d", &a, &n, &p);
			ans += a * p;
		}
		printf("%d\n", ans);
	}

	return 0;
}
