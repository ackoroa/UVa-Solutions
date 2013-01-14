#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int TC, n, p[20], total;
	int i, count = 0;

	scanf("%d", &TC);

	while (TC--) {
		count++;

		scanf("%d", &n);

		total = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			total += p[i];
		}
		int majorReq = total / 2;

		int subset[20], subsetLen = n - 1;
		for (i = 0; i < n; i++) {
			int k = 0;
			for (int j = 0; j < subsetLen; j++) {
				if (k != i)
					subset[j] = p[k];
				else {
					k++;
					subset[j] = p[k];
				}
				k++;
			}

			int power = 0, tVote, ownVote = p[i];
			for (int j = 0; j < (1 << subsetLen); j++) {
				tVote = 0;
				for (int k = 0; k < subsetLen; k++) {
					tVote += subset[k] * ((j >> k) % 2);
				}
				if ((tVote <= majorReq) && ((tVote + ownVote) > majorReq)) {
					power++;
					//cout << j << endl;
				}
			}
			printf("party %d has power index %d\n", i + 1, power);
		}
		printf("\n");
	}

	return 0;
}
