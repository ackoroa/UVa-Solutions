#include <cstdio>
#include <algorithm>
using namespace std;

bool inUse(int c, int s[], int b[]) {
	for (int i = 0; i < 3; i++) {
		if (c == s[i])
			return true;
	}
	for (int i = 0; i < 2; i++) {
		if (c == b[i])
			return true;
	}
	return false;
}

int main() {
	int sis[3], bro[2];
	while (scanf("%d %d %d %d %d", &sis[0], &sis[1], &sis[2], &bro[0], &bro[1]), sis[0]
			|| sis[1] || sis[2] || bro[0] || bro[1]) {
		sort(sis, sis + 3);
		sort(bro, bro + 2);
		int lc = 0;
		bool used[3] = { false, false, false };

		for (int i = 0; i < 2; i++) {
			bool found = false;
			for (int j = 0; j < 3; j++) {
				if ((sis[j] > bro[i]) && !used[j]) {
					used[j] = true;
					lc++;
					found = true;
					break;
				}
			}
			if (!found) {
				for (int j = 0; j < 3; j++) {
					if (!used[j])
						used[j] = true;
					break;
				}
			}

		}
		if (lc == 2) {
			printf("-1\n");
			continue;
		}

		int lastC = 0;
		if (lc != 0) {
			for (int i = 0; i < 3; i++) {
				if (!used[i])
					lastC = sis[i];
			}
		}

		int trumpC = lastC + 1;
		while (inUse(trumpC, sis, bro)) {
			trumpC++;
		}
		if (trumpC > 52)
			trumpC = -1;

		printf("%d\n", trumpC);
	}

	return 0;
}
