#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int tc, C, N1, N5, N10, totalMoney;
int memo[160][150][60];

int f(int bought, int n5, int n10) {
	if (memo[bought][n5][n10] != -1)
		return memo[bought][n5][n10];
	if (bought == C)
		return memo[bought][n5][n10] = 0;

	int n1 = totalMoney - 8 * bought - 5 * n5 - 10 * n10;
	int ans = 2e9;
	if (n1 >= 8)
		ans = min(ans, 8 + f(bought + 1, n5, n10));
	if (n5 >= 1 && n1 >= 3)
		ans = min(ans, 4 + f(bought + 1, n5 - 1, n10));
	if (n10 >= 1 && n1 >= 3)
		ans = min(ans, 4 + f(bought + 1, n5 + 1, n10 - 1));
	if (n5 >= 2)
		ans = min(ans, 2 + f(bought + 1, n5 - 2, n10));
	if (n10 >= 1)
		ans = min(ans, 1 + f(bought + 1, n5, n10 - 1));

	return memo[bought][n5][n10] = ans;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d %d", &C, &N1, &N5, &N10);
		totalMoney = N1 + 5 * N5 + 10 * N10;

		memset(memo, -1, sizeof(memo));
		printf("%d\n", f(0, N5, N10));
	}

	return 0;
}
