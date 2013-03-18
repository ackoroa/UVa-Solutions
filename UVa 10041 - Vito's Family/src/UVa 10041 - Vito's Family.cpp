#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, r, median, x[505], ans;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &r);

		for (int i = 0; i < r; i++) {
			scanf("%d", &x[i]);
		}
		sort(x, x + r);
		median = x[r / 2];

		ans = 0;
		for (int i = 0; i < r; i++) {
			ans += abs(median - x[i]);
		}

		printf("%d\n", ans);
	}

	return 0;
}
