#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int n, s, *x;
	x = (int*) malloc(300000*4);

	while (scanf("%d %d", &n, &s) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}

		int low = 0, hi = 0, sum = x[0], lowestWS = 1000000;
		while (hi < n) {
			if (sum >= s) {
				int temp = hi - low + 1;
				if (temp < lowestWS)
					lowestWS = temp;
			}
			if (sum >= s && low < hi) {
				sum -= x[low];
				low++;
			} else if (sum < s) {
				hi++;
				if (hi < n)
					sum += x[hi];
			}
		}

		if (lowestWS == 1000000)
			lowestWS = 0;
		printf("%d\n", lowestWS);

	}

	return 0;
}
