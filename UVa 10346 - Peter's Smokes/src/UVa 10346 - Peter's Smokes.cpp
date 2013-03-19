#include<cstdio>
using namespace std;

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) == 2) {
		printf("%d\n", n + (n - 1) / (k - 1));
	}
	return 0;
}
