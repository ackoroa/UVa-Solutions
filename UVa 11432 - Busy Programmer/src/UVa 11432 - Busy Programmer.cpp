#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long memo[35][35][35][2];
int D, G;

long long sched(int t0, int t1, int g, int cur) {
	if ((g < 0 && t0 > 0 && cur == 1) || (g < 0 && t1 > 0 && cur == 0) || t0 < 0
			|| t1 < 0)
		return 0;
	if (t0 == 0 && t1 == 0) {
		if (cur == 1)
			return 1;
		else
			return 0;
	}

	if (memo[t0][t1][g][cur] != -1)
		return memo[t0][t1][g][cur];

	if (cur == 0)
		return memo[t0][t1][g][cur] = sched(t0 - 1, t1, g - 1, 0)
				+ sched(t0, t1 - 1, G - 1, 1);
	else
		return memo[t0][t1][g][cur] = sched(t0 - 1, t1, G - 1, 0)
				+ sched(t0, t1 - 1, g - 1, 1);
}

int main(void) {

	int count = 0;
	while (scanf("%d %d", &D, &G), (D != -1) && (G != -1)) {
		count++;

		memset(memo, -1, sizeof(memo));
		long long ans = (D == 0 && G == 0) ? 1 : sched(D - 1, D, G - 1, 0) * 2;

		printf("Case %d: %lld\n", count, ans);
	}
	return 0;
}
