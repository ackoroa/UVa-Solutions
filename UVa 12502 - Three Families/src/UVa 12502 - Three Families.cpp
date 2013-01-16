#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int TC;

	scanf("%d", &TC);
	while (TC--) {
		int a, b, mon;
		scanf("%d %d %d", &a, &b, &mon);

		double field = a + b;
		double ans;
		if (a <= field / 3)
			ans = 0;
		else if (a < 2 * field / 3)
			ans = ((double) mon * ((double) a - field / 3.0)) / (field / 3.0);
		else
			ans = mon;

		printf("%.0lf\n", ans);
	}

	return 0;
}
