#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	Point() {
	}
	Point(int x, int y) :
			x(x), y(y) {
	}
	int cross(Point a, Point b) {
		return (this->x - a.x) * (b.y - a.y) - (this->y - a.y) * (b.x - a.x);
	}
	bool left(Point a, Point b) {
		return cross(a, b) < 0;
	}

	bool operator <(const Point& p) const {
		if (this->x != p.x)
			return this->x < p.x;
		return this->y < p.y;
	}
	bool operator ==(const Point& p) const {
		return this->x == p.x and this->y == p.y;
	}
	bool onLineSegment(Point a, Point b) {
		return cross(a, b) == 0 && min(a, b) < *this && *this < max(a, b);
	}
};

int convexHull(Point* P, int n, Point* S) {
	sort(P, P + n);

	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m >= 2 && S[m - 1].left(S[m - 2], P[i]))
			m--;
		S[m++] = P[i];
	}
	m--;

	for (int i = n - 1, k = m; i >= 0; i--) {
		while (m >= k + 2 && S[m - 1].left(S[m - 2], P[i]))
			m--;
		S[m++] = P[i];
	}
	m--;

	return m;
}

bool inPolygon(Point* P, int n, Point v) {
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		if (!v.left(P[i], P[j]))
			return false;
	}
	return true;
}

bool checkInside(Point* P, int n, Point v) {
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		if (v == P[i] || v.onLineSegment(P[i], P[j]))
			return true;
	}
	return inPolygon(P, n, v);
}

Point M[250], R[250], MHull[250], CHull[250];

int main() {
	int c, r, o, count = 1;
	while (scanf("%d %d %d", &c, &r, &o), c || r || o) {
		for (int i = 0; i < c; i++)
			scanf("%d %d", &M[i].x, &M[i].y);

		for (int i = 0; i < r; i++)
			scanf("%d %d", &R[i].x, &R[i].y);

		int cs = convexHull(M, c, MHull);
		int rs = convexHull(R, r, CHull);

		printf("Data set %d:\n", count++);
		for (int i = 0; i < o; i++) {
			Point p;
			scanf("%d %d", &p.x, &p.y);
			printf("     Citizen at (%d,%d) is ", p.x, p.y);
			if (checkInside(MHull, cs, p) && cs > 2)
				printf("safe.\n");
			else if (checkInside(CHull, rs, p) && rs > 2)
				printf("robbed.\n");
			else
				printf("neither.\n");
		}
		printf("\n");

	}
}
