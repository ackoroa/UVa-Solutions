#include <cstdio>
using namespace std;

int left[100005], right[100005];

int main() {
	int s, b;

	while (scanf("%d %d", &s, &b), s || b) {
		for (int i = 1; i <= s; i++) {
			left[i] = i - 1;
			right[i] = i + 1;
		}
		right[s] = -1;
		left[1] = -1;

		int l, r;
		for (int i = 0; i < b; i++) {
			scanf("%d %d", &l, &r);

			left[right[r]] = left[l];
			if (left[l] != -1)
				printf("%d", left[l]);
			else
				printf("*");

			right[left[l]] = right[r];
			if (right[r] != -1)
				printf(" %d\n", right[r]);
			else
				printf(" *\n");
		}
		printf("-\n");
	}

	return 0;
}
