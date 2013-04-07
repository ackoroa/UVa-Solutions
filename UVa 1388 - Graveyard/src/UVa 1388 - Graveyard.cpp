#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	double pos, ans;
	while (scanf("%d %d", &n, &m) != EOF) {
		ans = 0;
		for (int i = 1; i < n; i++) {
			pos = (i * 1.0 / n) * (n + m);
			ans += fabs(pos - floor(pos + 0.5)) / (n + m);
		}
		printf("%.4lf\n", ans * 10000);
	}
	return 0;
}
