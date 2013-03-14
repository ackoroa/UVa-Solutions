#include <cstdio>
using namespace std;

int main() {
	int tc, n, r, l, pos;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);

		r = -1000000000;
		l = 1000000000;
		for (int i = 0; i < n; i++) {
			scanf("%d", &pos);
			if (pos > r)
				r = pos;
			if (pos < l)
				l = pos;
		}
		printf("%d\n", 2 * (r - l));
	}
}
