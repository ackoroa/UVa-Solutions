#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	long long n;

	while (scanf("%lld", &n), n) {
		if (floor(sqrt(n)) == ceil(sqrt(n)))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
