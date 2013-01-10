#include <cstdio>
#include <iostream>
using namespace std;

int tapeLen, n, trackLen[20];
int ans, nearestTotal;

void choose(int total, int mask, int p) {
	if (total > tapeLen)
		return;
	if (total > nearestTotal) {
		nearestTotal = total;
		ans = mask;
	}
	if (p >= n)
		return;

	choose(total + trackLen[p], mask | (1 << p), p + 1);
	choose(total, mask, p + 1);
}

int main() {
	while (scanf("%d %d", &tapeLen, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &trackLen[i]);
		}

		ans = -1;
		nearestTotal = -1;
		choose(0, 0, 0);

		for (int i = 0; i < n; i++) {
			if ((ans >> i) % 2)
				printf("%d ", trackLen[i]);
		}
		printf("sum:%d\n", nearestTotal);
	}

	return 0;
}
