#include <cstdio>
#include <algorithm>
using namespace std;

int *city;

int main() {
	city = (int*) malloc(20000 * 4);
	int l, h, r, i, rmax = -1;

	for (i = 0; i <= 20000; i++) {
		city[i] = 0;
	}

	while (scanf("%d %d %d", &l, &h, &r) != EOF) {
		for (i = l; i < r; i++) {
			city[i + 500] = max(city[i + 500], h);
		}
		rmax = max(r, rmax);
	}

	i = 0;
	while (city[i] == 0)
		i++;
	while (true) {
		printf("%d ", i - 500);

		int curH = city[i];
		printf("%d", curH);

		while (city[i] == curH) {
			i++;
		}
		if (i > rmax + 500)
			break;

		printf(" ");
	}
	printf("\n");

	return 0;
}
