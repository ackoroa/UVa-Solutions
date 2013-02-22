#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

typedef long long ll;

ll memo[16][16];
int givenRow[16], n;

ll place(int col, int row) {
	if (col == n)
		return 1;
	if (memo[col][row] != -1)
		return memo[col][row];

	ll ans = 0;
	if (givenRow[col + 1] == 0) {
		for (int i = 1; i <= n; i++) {
			if ((i != row + 1) && (i != row) && (i != row - 1))
				ans += place(col + 1, i);
		}
	} else if ((givenRow[col + 1] != row + 1) && (givenRow[col + 1] != row)
			&& (givenRow[col + 1] != row - 1))
		ans += place(col + 1, givenRow[col + 1]);

	return memo[col][row] = ans;
}

int main() {
	char s[16], c;

	while (scanf("%s", s) != EOF) {
		n = strlen(s);
		for (int i = 1; i <= n; i++) {
			c = s[i - 1];
			if (c == '?')
				givenRow[i] = 0;
			else if (isdigit(c))
				givenRow[i] = c - '0';
			else
				givenRow[i] = c - 'A' + 10;
		}

		memset(memo, -1, sizeof(memo));
		ll ans = 0;
		if (givenRow[1] == 0) {
			for (int i = 1; i <= n; i++) {
				ans += place(1, i);
			}
		} else
			ans += place(1, givenRow[1]);

		printf("%lld\n", ans);
	}

	return 0;
}
