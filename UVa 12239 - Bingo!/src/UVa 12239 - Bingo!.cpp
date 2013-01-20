#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main() {
	int n, b, x[100];

	while (scanf("%d %d", &n, &b), n || b) {
		set<int> checker;
		for (int i = 0; i < b; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i < b; i++) {
			for (int j = i; j < b; j++) {
				int d = abs(x[i] - x[j]);
				if (d <= n)
					checker.insert(d);
			}
		}

		if (checker.size() == n + 1)
			printf("Y\n");
		else
			printf("N\n");
	}

	return 0;
}
