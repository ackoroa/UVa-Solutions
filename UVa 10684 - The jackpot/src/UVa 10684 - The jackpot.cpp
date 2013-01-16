#include <cstdio>
using namespace std;

int main() {
	int n, i, x[100000];

	while (scanf("%d", &n), n) {
		for (i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}

		int max = 0, temp = 0;
		for (i = 0; i < n; i++) {
			temp += x[i];
			if (temp > max)
				max = temp;
			if (temp < 0)
				temp = 0;
		}

		if (max > 0)
			printf("The maximum winning streak is %d.\n", max);
		else
			printf("Losing streak.\n");
	}

	return 0;
}
