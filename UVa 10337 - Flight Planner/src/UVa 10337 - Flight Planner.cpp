#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int windSpd[10][1005];
int memo[10][1005];
int tc, x;

int fuel(int alt, int dist) {
	if (alt > 9 || alt < 0 || dist > x)
		return 1e9;

	//if cannot go to alt==0 before destination
//	if (alt == 0 && !(dist == 0 || dist == x))
//		return 1e9;

	if (dist == x) {
		if (alt == 0)
			return 0;
		else
			return 1e9;
	}

	if (memo[alt][dist] != -1)
		return memo[alt][dist];

	return memo[alt][dist] = min(
			60 - windSpd[alt][dist] + fuel(alt + 1, dist + 1),
			min(30 - windSpd[alt][dist] + fuel(alt, dist + 1),
					20 - windSpd[alt][dist] + fuel(alt - 1, dist + 1)));
}

int main() {
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d", &x);
		x /= 100;

		for (int alt = 9; alt >= 0; alt--) {
			for (int dist = 0; dist < x; dist++) {
				scanf("%d", &windSpd[alt][dist]);
			}
		}

		memset(memo, -1, sizeof(memo));

		int ans = fuel(0, 0);
		printf("%d\n\n", ans);
	}

	return 0;
}
