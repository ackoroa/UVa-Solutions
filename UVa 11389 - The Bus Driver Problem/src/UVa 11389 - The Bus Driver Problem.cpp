#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n, d, r;
	int hrs, morn[100], aft[100];
	int pay;

	while (scanf("%d %d %d", &n, &d, &r), n || d || r) {
		pay = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &morn[i]);
		}
		sort(morn, morn + n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &aft[i]);
		}
		sort(aft, aft + n, greater<int>());

		for (int i = 0; i < n; i++) {
			hrs = morn[i] + aft[i];
			if (hrs > d)
				pay += (hrs - d) * r;
		}

		printf("%d\n", pay);
	}

	return 0;
}
