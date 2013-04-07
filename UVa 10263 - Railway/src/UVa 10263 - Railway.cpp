#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

double degToRad(double d) {
	return d * PI / 180.0;
}
double radToDeg(double r) {
	return r * 180.0 / PI;
}

struct point {
	double x, y;
	point() {
		x = INF, y = INF;
	}
	point(double _x, double _y) {
		x = _x, y = _y;
	}
	bool operator <(point other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line {
	double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) // vertical line
		l.a = 1.0, l.b = 0.0, l.c = -p1.x;
	else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

struct vec {
	double x, y;
	vec(double _x, double _y) {
		x = _x, y = _y;
	}
};

vec toVector(point p1, point p2) {
	return vec(p2.x - p1.x, p2.y - p1.y);
}

vec scaleVector(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point A, point B, point &c) {
	vec Ap = toVector(A, p), AB = toVector(A, B);
	double u = dot(Ap, AB) / norm_sq(AB);
	c = translate(A, scaleVector(AB, u));
	return dist(p, c);
}

double distToLineSegment(point p, point A, point B, point &c) {
	vec Ap = toVector(A, p), AB = toVector(A, B);
	double u = dot(Ap, AB) / norm_sq(AB);
	if (u < 0.0) {
		c = point(A.x, A.y);
		return dist(p, A);
	}
	if (u > 1.0) {
		c = point(B.x, B.y);
		return dist(p, B);
	}
	return distToLine(p, A, B, c);
}

int main() {
	double x, y;
	int n;
	point rails[10010];

	while (scanf("%lf\n%lf\n%d", &x, &y, &n) != EOF) {
		point m(x, y);

		for (int i = 0; i < n + 1; i++) {
			scanf("%lf\n%lf", &x, &y);
			rails[i] = point(x, y);
		}

		double ans = INF;
		point ansP, tP;
		for (int i = 0; i < n; i++) {
			double t = distToLineSegment(m, rails[i], rails[i + 1], tP);
			if (t < ans) {
				ans = t;
				ansP = tP;
			}
		}

		printf("%.4lf\n%.4lf\n", ansP.x, ansP.y);
	}

	return 0;
}
