#include <cstdio>
#include <cmath>
#include <map>
#include <cctype>
#include <cstring>
using namespace std;

map<int, int> fibIdx, revFibIdx;

int fib(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (fibIdx.count(n) != 0)
		return fibIdx[n];

	int ans = fib(n - 1) + fib(n - 2);
	fibIdx[n] = ans;
	revFibIdx[ans] = n;
	return ans;
}

void init() {
	fibIdx[1] = 1;
	fibIdx[2] = 2;
	revFibIdx[1] = 1;
	revFibIdx[2] = 2;
	fib(46);
}

int main() {
	int tc, n, i;
	char s[10001], ans[10001], c;
	int key[100];

	init();

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		int max = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &key[i]);
			if (key[i] > max)
				max = key[i];
		}

		i = 0;
		scanf("%c", &c);
		while (true) {
			scanf("%c", &c);
			if (c == '\n')
				break;
			if (isupper(c))
				s[i++] = c;
		}

		for (i = 0; i < revFibIdx[max]; i++) {
			ans[i] = ' ';
		}
		for (i = 0; i < n; i++) {
			ans[revFibIdx[key[i]] - 1] = s[i];
		}
		ans[revFibIdx[max]] = '\0';

		printf("%s\n", ans);
	}

	return 0;
}
