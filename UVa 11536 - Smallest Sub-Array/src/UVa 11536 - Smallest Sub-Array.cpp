#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int freq[105], *x;

bool covered(int k) {
	for (int i = 1; i <= k; i++) {
		if (freq[i] <= 0)
			return false;
	}
	return true;
}

int main() {
	int n, m, k, tc, count = 0;
	x = (int*) malloc(1000004 * 4);

	scanf("%d", &tc);

	while (tc--) {
		count++;
		scanf("%d %d %d", &n, &m, &k);

		x[0] = 1;
		x[1] = 2;
		x[2] = 3;

		for (int i = 3; i < n; i++) {
			x[i] = (x[i - 1] + x[i - 2] + x[i - 3]) % m + 1;
		}

		for (int i = 0; i < 105; i++)
			freq[i] = 0;
		int lo = 0, hi = 0, min = 1000005;
		freq[x[hi]]++;

		while (true) {
			if (covered(k)) {
				if ((hi - lo + 1) < min)
					min = hi - lo + 1;
				if (x[lo] <= k)
					freq[x[lo]]--;
				lo++;
			} else {
				hi++;
				if (hi < n) {
					if (x[hi] <= k)
						freq[x[hi]]++;
				} else {
					break;
				}
			}
		}

		printf("Case %d: ", count);
		if (min == 1000005)
			printf("sequence nai\n");
		else
			printf("%d\n", min);
	}

	return 0;
}
