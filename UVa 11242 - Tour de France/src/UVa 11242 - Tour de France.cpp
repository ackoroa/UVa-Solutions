#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int f, r;
	int fv[10], rv[10];
	double drive[100];

	while (scanf("%d",&f), f) {
		scanf("%d", &r);

		for (int i = 0; i < f; i++) {
			scanf("%d", &fv[i]);
		}
		for (int i = 0; i < r; i++) {
			scanf("%d", &rv[i]);
		}

		int k = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < f; j++) {
				drive[k] = (double) rv[i] / (double) fv[j];
				k++;
			}
		}
		sort(drive, drive + k);

		double maxS =-1;
		for (int i = 0; i < k - 1; i++) {
			maxS = max(maxS,drive[i + 1] / drive[i]);
		}

		printf("%.2lf\n",maxS);
	}

	return 0;
}
