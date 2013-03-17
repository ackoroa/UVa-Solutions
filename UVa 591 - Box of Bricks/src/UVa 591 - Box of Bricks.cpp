#include <cstdio>
using namespace std;

int main() {
	int n, sum, havg, x[55], ans, count = 1;

	while (scanf("%d", &n), n) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
			sum += x[i];
		}
		havg = sum / n;
		ans = 0;
		for (int i = 0; i < n; i++) {
			if (x[i] > havg)
				ans += x[i] - havg;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", count++, ans);
	}

	return 0;
}
