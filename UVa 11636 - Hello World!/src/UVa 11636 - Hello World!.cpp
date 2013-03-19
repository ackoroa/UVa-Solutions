#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, cnt = 1;
	while (scanf("%d", &n), n >= 0) {
		printf("Case %d: %.0lf\n", cnt++, max(0.0,ceil(log(n) / log(2))));
	}

	return 0;
}
