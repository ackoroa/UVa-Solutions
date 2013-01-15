#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int k;
	int ans[87] = { 1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21, 13, 26, 14, 11, 23,
			22, 9, 73, 17, 42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 38, 15, 54, 27,
			9, 61, 38, 22, 19, 178, 38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 72,
			133, 41, 10, 82, 92, 64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22,
			176, 10, 57, 137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22,
			54, 52, 113, 15 };

	while (scanf("%d", &k), k) {
		printf("%d\n",ans[k-13]);
	/*
	for (k = 13; k < 100; k++) {
		long m;
		for (m = 1; m < 2000000000; m++) {
			int pos = 0;
			bool on[100];
			memset(on, true, 100);

			for (int i = 0; i < k - 1; i++) {
				on[pos] = false;
				int count = m;
				while (count) {
					pos = (pos + 1) % k;
					if (on[pos])
						count--;
				}
			}
			if (on[12])
				break;
		}
		printf("%ld, ", m);
		*/
	}

	return 0;
}
