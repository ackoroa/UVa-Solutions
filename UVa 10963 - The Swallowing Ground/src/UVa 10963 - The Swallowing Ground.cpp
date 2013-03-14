#include <cstdio>
using namespace std;

int main() {
	int tc, n, up, down;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);

		bool yes = true;
		scanf("%d %d", &up, &down);
		int d = up - down;

		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d", &up, &down);
			if (d != up - down)
				yes = false;
		}

		if (yes)
			printf("yes\n");
		else
			printf("no\n");

		if (tc)
			printf("\n");
	}

	return 0;
}
