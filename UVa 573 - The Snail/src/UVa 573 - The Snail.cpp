#include <cstdio>
using namespace std;

int main() {
	int h, u, d, f;

	while (scanf("%d %d %d %d", &h, &u, &d, &f), h || u || d || f) {
		double currU = u;
		double distMin = u * (f / 100.0);
		double currH = 0;
		int currDay = 0;

		do {
			currDay++;
			//printf("init: %lf climbed: %lf ", currH, currU);

			currH += currU;
			//printf("afterU: %lf ", currH);
			if (currH > h){
				printf("success on day ");
				break;
			}
			currH -= d;
			//printf("afterD: %lf\n",currH);
			if (currH < 0){
				printf("failure on day ");
				break;
			}
			currU -= distMin;
			if (currU < 0)
				currU = 0;
		} while (true);

		printf("%d\n",currDay);
	}

	return 0;
}
