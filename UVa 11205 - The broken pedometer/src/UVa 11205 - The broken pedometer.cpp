#include <cstdio>
#include <set>
#include <utility>
using namespace std;

int main() {
	int TC, p, n;
	int code[100];

	scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &p);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			int c = 0, x;
			for (int j = 0; j < p; j++) {
				c <<= 1;
				scanf("%d", &x);
				c |= x;
			}
			code[i] = c;
		}

		int minimum = 100000;
		for (int i = 0; i < (1 << p); i++) {
			set<int> checker;
			bool diffable = true;
			for (int j = 0; j < n; j++) {
				int bCode = code[j] & i;
				pair<set<int>::iterator, bool> pr = checker.insert(bCode);
				if (pr.second == false) {
					diffable = false;
					break;
				}
			}
			if (diffable) {
				int ans = 0, ansCode = i;
				while (ansCode > 0) {
					if (ansCode % 2 == 1)
						ans++;
					ansCode >>= 1;
				}
				minimum = min(minimum,ans);
			}
		}

		printf("%d\n", minimum);
	}

	return 0;
}
