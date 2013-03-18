#include <cstdio>
using namespace std;

long long a[5001][5001];

int main() {
	int n, k;
	unsigned long long ans;

	while (scanf("%d %d", &n, &k), n || k) {

		ans = 1;
		if (k > (n / 2))
			k = n - k;

		for (int i = 0; i < k; i++) {
			ans *= (n - i);
			ans /= (1 + i);
		}

		printf("%llu\n", ans);
	}

	return 0;
}
