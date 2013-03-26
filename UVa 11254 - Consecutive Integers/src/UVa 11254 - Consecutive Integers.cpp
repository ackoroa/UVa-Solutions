#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int s, a, n;

	while (scanf("%d", &s), s != -1) {
		for (n = (int) sqrt(2 * s); n > 0; n--) {
			if ((2 * s + n - n * n) % (2 * n) == 0) {
				a = (2 * s + n - n * n) / (2 * n);
				break;
			}
		}

		printf("%d = %d + ... + %d\n", s, a, a + n - 1);
	}

	return 0;
}
