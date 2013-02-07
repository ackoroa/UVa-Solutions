#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[200][20];
int gList[20][20];
int ng[20];
int tc, m, g;

int shop(int money, int curG) {
	if (money < 0)
		return -1e6;
	if (curG == g)
		return m - money;

	if (memo[money][curG] != -1)
		return memo[money][curG];

	int ans = -1e6;
	for (int i = 0; i < ng[curG]; i++) {
		ans = max(ans, shop(money - gList[curG][i], curG + 1));
	}

	return memo[money][curG] = ans;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &m, &g);

		for (int i = 0; i < g; i++) {
			scanf("%d", &ng[i]);
			for (int j = 0; j < ng[i]; j++) {
				scanf("%d", &gList[i][j]);
			}
		}

		memset(memo, -1, 200 * 20 * 4);
		int ans = shop(m, 0);

		if (ans > 0)
			printf("%d\n", ans);
		else
			printf("no solution\n");
	}

	return 0;
}
