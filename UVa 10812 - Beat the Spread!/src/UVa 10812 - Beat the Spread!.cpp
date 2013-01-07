#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int TC;

	scanf("%d", &TC);

	int s, d, x, y;
	while (TC--) {
		scanf("%d %d", &s, &d);
		x = (s + d) / 2;
		y = s - x;

		if (((s + d) % 2 != 0) || (x + y != s) || (abs(x - y) != d) || x < 0
				|| y < 0)
			printf("impossible\n");
		else
			printf("%d %d\n", max(x, y), min(x, y));
	}

	return 0;
}
