#include <cstdio>
using namespace std;

int main() {
	int TC, count = 0;

	scanf("%d", &TC);
	while (TC--) {
		count++;
		int n, ans, m;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			if (i == n / 2)
				ans = m;
		}

		printf("Case %d: %d\n", count, ans);
	}

	return 0;
}
