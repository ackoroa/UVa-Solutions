#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef unsigned long long ull;

int n, x;
ull memo[25][150];

ull gcd(ull n, ull m) {
	return m == 0 ? n : gcd(m, n % m);
}

ull nEvent(int n, int score) {
	if (n == 0) {
		if (score >= x)
			return 1;
		else
			return 0;
	}
	if (memo[n][score] != -1)
		return memo[n][score];

	ull ans = 0;
	for (int i = 1; i <= 6; i++) {
		ans += nEvent(n - 1, score + i);
	}

	return memo[n][score] = ans;
}

int main() {
	ull event, space, esgcd;

	while (scanf("%d %d", &n, &x), n || x) {
		memset(memo, -1, sizeof(memo));
		space = pow(6.0, n);
		event = nEvent(n, 0);

		esgcd = gcd(space, event);
		event = event / esgcd;
		space = space / esgcd;

		if (event == 0)
			printf("0\n");
		else if (space == 1)
			printf("%llu\n", event);
		else
			printf("%llu/%llu\n", event, space);
	}

	return 0;
}
