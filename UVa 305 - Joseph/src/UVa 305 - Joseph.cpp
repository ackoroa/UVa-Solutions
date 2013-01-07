#include <cstdio>
using namespace std;

int main() {
	int k;
	int ans[13] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901,
			1358657, 2504881 };

	while (scanf("%d", &k), k) {
		printf("%d\n",ans[k-1]);

		/*
		long m;
		for (m = k + 1; m < 2000000000; m++) {
			int pos = 0;
			bool found = true;
			for (int i = 0; i < k; i++) {
				pos = (pos + m - 1) % ((2 * k) - i);
				if (pos < k) {
					found = false;
					break;
				}
			}
			if (found)
				break;
		}
		printf("%ld\n", m);
		*/
	}

	return 0;
}
