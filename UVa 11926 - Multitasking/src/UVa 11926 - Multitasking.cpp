#include <cstdio>
#include <bitset>
using namespace std;

bitset<2000005> bs;

int main() {
	int one, rep, s, e, itv;
	bool conflict;
	while (scanf("%d %d", &one, &rep), one || rep) {
		conflict = false;

		for (int i = 0; i < one; i++) {
			scanf("%d %d", &s, &e);
			if (!conflict) {
				for (int j = 2 * s + 1; j <= 2 * e; j++) {
					if (bs.test(j)) {
						conflict = true;
						break;
					}
					bs.set(j);
				}
			}
		}

		for (int i = 0; i < rep; i++) {
			scanf("%d %d %d", &s, &e, &itv);
			if (!conflict) {
				while (true) {
					for (int j = 2 * s + 1; j <= 2 * e; j++) {
						if (bs.test(j)) {
							conflict = true;
							break;
						}
						bs.set(j);
					}
					s += itv;
					e += itv;
					if (s > 1000000 && e > 1000000)
						break;
					else if (e > 1000000)
						e = 1000000;
				}
			}
		}

		if (conflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");

		for (int i = 0; i < 2000005; i++) {
			bs.reset(i);
		}
	}

	return 0;
}
