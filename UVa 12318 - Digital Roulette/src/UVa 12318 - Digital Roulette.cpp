#include <cstdio>
#include <set>
using namespace std;

int n, m, k, a[10];

long long P(int x) {
	long long ans = 0, pow = 1;
	for (int i = 0; i <= k; i++) {
		if (a[i] != 0)
			ans = (ans + a[i] * pow) % (n + 1);
		pow = (pow * x) % (n + 1);
	}
	return ans;
}

int main() {
	int ans;
	long long spinRes;
	set<long long> checker;

	while (scanf("%d %d", &n, &m), n || m) {
		scanf("%d", &k);

		for (int i = 0; i <= k; i++) {
			scanf("%d", &a[i]);
		}

		ans = 0;
		checker.clear();
		for (int i = 0; i <= m; i++) {
			spinRes = P(i);
			if (checker.insert(spinRes).second) {
				ans++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
