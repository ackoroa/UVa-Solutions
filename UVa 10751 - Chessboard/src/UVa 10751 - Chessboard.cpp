#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int tc, n;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		if (n > 1)
			printf("%.3lf\n", (4 * n - 4) + sqrt(2) * (n - 2) * (n - 2));
		else
			printf("0.000\n");
	}

	return 0;
}
