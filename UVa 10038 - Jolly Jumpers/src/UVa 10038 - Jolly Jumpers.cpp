#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main() {
	int n, m, l;

	while (scanf("%d", &n) != EOF) {
		set<int> checker;
		bool jolly = true;

		scanf("%d", &m);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d", &l);
			m = abs(m - l);
			checker.insert(m);
			m = l;
		}

		if (checker.size() != n - 1)
			jolly = false;
		if (checker.count(0) > 0)
			jolly = false;
		if (checker.upper_bound(n - 1) != checker.end())
			jolly = false;

		if (jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}
