#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-9

struct point {
	double x, y; // we use double for most examples in this source code
	point() {
	}
	;
	point(double _x, double _y) {
		x = _x, y = _y;
	}
	bool operator <(point p) const { // declare as const otherwise won't compile
		if (fabs(x - p.x) > EPS)
			return x < p.x;
		return y < p.y;
	}
	bool operator ==(point p) const {
		return fabs(x - p.x) < EPS && fabs(x - p.y) < EPS;
	}
};

double cross(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(point a, point b) {
	if (fabs(a.y - b.y) > EPS)
		return a.y < b.y;
	return a.x < b.x;
}

vector<point> CHAMC(vector<point> P) {
	vector<point> H;
	sort(P.begin(), P.end(), cmp);
	int n = P.size();
	for (int i = 0; i < n; i++) {
		while (H.size() >= 2
				&& cross(H[H.size() - 2], H[H.size() - 1], P[i]) <= 0)
			H.pop_back();
		H.push_back(P[i]);
	}
	int l = H.size() + 1;
	for (int i = n - 1; i >= 0; i--) {
		while (H.size() >= l
				&& cross(H[H.size() - 2], H[H.size() - 1], P[i]) <= 0)
			H.pop_back();
		H.push_back(P[i]);
	}
	return H;
}

int main() {
	int tc, n, x, y;
	vector<point> P;

	scanf("%d", &tc);
	printf("%d\n", tc);

	while (tc--) {
		P.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			P.push_back(point(x, y));
		}
		if (tc)
			scanf("%d", &x);

		P = CHAMC(P);

		printf("%d\n", (int) P.size());
		for (int i = 0; i < (int) P.size(); i++) {
			printf("%.0lf %.0lf\n", P[i].x, P[i].y);
		}
		if (tc)
			printf("-1\n");
	}

	return 0;
}
