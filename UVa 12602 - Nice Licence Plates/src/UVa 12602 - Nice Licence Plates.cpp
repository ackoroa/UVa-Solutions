#include <cstdio>
#include <cmath>
using namespace std;

int lval(char l[]) {
	return 26 * 26 * (l[0] - 'A') + 26 * (l[1] - 'A') + (l[2] - 'A');
}

int main() {
	char lll[4];
	int tc, d;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%3s-%d", lll, &d);
		if (abs(lval(lll) - d) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}

	return 0;
}
