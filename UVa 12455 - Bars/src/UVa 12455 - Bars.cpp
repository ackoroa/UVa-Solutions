#include <cstdio>
#include <set>
using namespace std;

int bar[30];

int main() {
	int tc, n;
	long long total, target;
	set<long long> checker;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld\n%d", &target, &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &bar[i]);
		}

		int n2 = n / 2, n1 = n - n2;
		for (int s = 0; s < (1 << n1); s++) {
			total = 0;
			for (int i = 0; i < n1; i++) {
				if (1 & (s >> i)) {
					total += bar[i];
				}
			}
			checker.insert(total);
		}

		for (int s = 0; s < (1 << n2); s++) {
			total = 0;
			for (int i = 0; i < n2; i++) {
				if (1 & (s >> i)) {
					total += bar[n1+i];
				}
			}
			if(checker.count(target-total)) break;
		}

		if(checker.count(target-total)) printf("YES\n");
		else printf("NO\n");

		checker.clear();
	}

	return 0;
}
