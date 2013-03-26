#include <cstdio>
using namespace std;

int main() {
	int a, b;
	long long n;

	while (scanf("%d %d %lld", &a, &b, &n), a || b || n) {
		n %= 5;

		if (n == 0)
			printf("%d\n", a);
		if (n == 1)
			printf("%d\n", b);
		if (n == 2)
			printf("%d\n", (1 + b) / a);
		if (n == 3)
			printf("%d\n", (1 + a + b) / (a * b));
		if (n == 4)
			printf("%d\n", (1 + a) / b);
	}

	return 0;
}
