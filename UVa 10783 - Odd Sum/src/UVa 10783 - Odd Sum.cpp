#include <cstdio>
using namespace std;

int main() {
	int tc;
	int a, b, count = 1;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d\n%d", &a, &b);

		int ans = 0;
		for (int i = a; i <= b; i += 2) {
			if (i % 2 == 0)
				i++;
			ans += i;
		}

		printf("Case %d: %d\n", count++, ans);
	}

	return 0;
}
