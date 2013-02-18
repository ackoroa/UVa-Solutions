#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;

char s[205];
long long memo[205];
int n, tc;

long long f(int i) {
	if (memo[i] != -1)
		return memo[i];
	if (i == n)
		return memo[i] = 0;
	if (s[i] == '0')
		return memo[i] = f(i + 1);

	int k = 1, j;
	long long ans = 0, pref;
	while (true) {
		pref = 0;
		for (j = i; (j < i + k); j++) {
			pref = pref * 10 + (s[j] - '0');
		}
		if (pref > INT_MAX)
			break;

		ans = max(ans, (int) pref + f(i + k));
		k++;

		if (i + k > n)
			break;
	}

	return memo[i] = ans;
}

int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%s", s);

		n = strlen(s);
		memset(memo, -1, sizeof(memo));
		long long ans = f(0);

		printf("%lld\n", ans);
	}

	return 0;
}
