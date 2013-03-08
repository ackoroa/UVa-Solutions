#include <cstdio>
using namespace std;

int main() {
	int init, c1, c2, c3, ans;
	while (scanf("%d %d %d %d", &init, &c1, &c2, &c3), init || c1 || c2 || c3) {
		ans = 1080;
		ans += (init - c1) > 0 ? (init - c1) * 9 : (init - c1 + 40) * 9;
		ans += (c2 - c1) > 0 ? (c2 - c1) * 9 : (c2 - c1 + 40) * 9;
		ans += (c2 - c3) > 0 ? (c2 - c3) * 9 : (c2 - c3 + 40) * 9;
		printf("%d\n", ans);
	}

	return 0;
}
