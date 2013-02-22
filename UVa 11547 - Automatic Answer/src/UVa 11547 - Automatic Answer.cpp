#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int tc;
	long long n;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld", &n);
		n = abs((((n * 63 + 7492) * 5 - 498)/10)%10);
		printf("%lld\n", n);
	}

	return 0;
}
