#include <cstdio>
#include <cmath>
using namespace std;

#define PI acos(-1.0)

double degToRad(double d) {
	return d * PI / 180.0;
}

int main() {
	int l, w, h, theta;
	double ans;

	while (scanf("%d %d %d %d", &l, &w, &h, &theta) != EOF) {
		double hprime = tan(degToRad(theta)) * l;
		if (hprime <= h) {
			ans = l * (h - hprime / 2.0) * w;
		} else {
			theta = 90 - theta;
			ans = (h * tan(degToRad(theta)) * h / 2.0) * w;
		}

		printf("%.3lf mL\n", ans);
	}

	return 0;
}
