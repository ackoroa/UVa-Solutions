#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n, c[35];
int memo[35][645][645];

int solve(int nth, int diff1, int diff2) {
	if (nth == n)
		return max(diff1, diff2);
	if (memo[nth][diff1][diff2] != -1)
		return memo[nth][diff1][diff2];

	// to a
	int ans = solve(nth + 1, diff1 + c[nth], diff2 + c[nth]);

	// to b
	int diff1p = diff1 - c[nth];
	if (diff1p >= 0)
		ans = min(ans, solve(nth + 1, diff1p, diff2));
	else
		ans = min(ans, solve(nth + 1, -diff1p, diff2 - diff1p));

	// to c
	int diff2p = diff2 - c[nth];
	if (diff2p >= 0)
		ans = min(ans, solve(nth + 1, min(diff1, diff2p), max(diff1, diff2p)));
	else
		ans = min(ans,
				solve(nth + 1, min(diff1 - diff2p, -diff2p),
						max(diff1 - diff2p, -diff2p)));

	return memo[nth][diff1][diff2] = ans;
}

int main() {
	int tc, count = 0;
	scanf("%d", &tc);
	while (tc--) {
		count++;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &c[i]);
		}

		memset(memo, -1, sizeof(memo));
		printf("Case %d: %d\n", count, solve(0, 0, 0));
	}

	return 0;
}
