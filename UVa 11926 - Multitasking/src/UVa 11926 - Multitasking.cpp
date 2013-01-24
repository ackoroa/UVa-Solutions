#include <cstdio>
#include <bitset>
using namespace std;

bitset<1000005> bs;

int main() {
	int one, rep, s, e, itv;
	bool conflict;
	while (scanf("%d %d", &one, &rep), one || rep) {
		conflict = false;

		for (int i = 0; i < one; i++) {
			scanf("%d %d", &s, &e);
			if (!conflict) {
				for (int j = s; j <= e; j++) {
					if (bs.test(j) && j != e)
						conflict = true;
					if (j == s && !bs.test(j + 1))
						conflict = false;
					bs.set(j);
					if (conflict)
						break;
				}
			}
		}

		for (int i = 0; i < rep; i++) {
			scanf("%d %d %d", &s, &e, &itv);
			if (!conflict) {
				while (true) {
					for (int j = s; j <= e; j++) {
						if (bs.test(j) && j != e)
							conflict = true;
						if (j == s && !bs.test(j + 1))
							conflict = false;
						bs.set(j);
						if(conflict)break;
					}
					if (conflict)
						break;
					s += itv;
					e += itv;
					if (s > 1000000 && e > 1000000)
						break;
					else if (e > 1000000)
						e = 1000000;
				}
			}
		}

		if(conflict) printf("CONFLICT\n");
		else printf("NO CONFLICT\n");

		for (int i = 0; i < 1000000; i++) {
			bs.reset(i);
		}
	}

	return 0;
}
