#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) {
	return d * PI / 180.0;
}

double RAD_to_DEG(double r) {
	return r * 180.0 / PI;
}

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

struct vec {
	double x, y; // similar to point
	vec(double _x, double _y) {
		x = _x, y = _y;
	}
};

vec toVector(point p1, point p2) { // convert 2 points to vector
	return vec(p2.x - p1.x, p2.y - p1.y);
}

double dist(point p1, point p2) { // get Euclidean distance of two points
	return hypot(p1.x - p2.x, p1.y - p2.y);
} // as shown earlier

// returns the area, which is half the determinant
// works for both convex and concave polygons
double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int) P.size() - 1; i++) {
		x1 = P[i].x;
		x2 = P[i + 1].x;
		y1 = P[i].y;
		y2 = P[i + 1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double angle(point a, point o, point b) { // returns angle aob in rad
	vec oa = toVector(o, a), ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
	return cross(toVector(p, q), toVector(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
	return fabs(cross(toVector(p, q), toVector(p, r))) < EPS;
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point p, const vector<point> &P) {
	if ((int) P.size() == 0)
		return false;
	double sum = 0; // assume first vertex = last vertex
	for (int i = 0; i < (int) P.size() - 1; i++) {
		if (ccw(p, P[i], P[i + 1]))
			sum += angle(P[i], p, P[i + 1]);   // left turn/ccw
		else
			sum -= angle(P[i], p, P[i + 1]);
	} // right turn/cw
	return fabs(fabs(sum) - 2 * PI) < EPS;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int) Q.size(); i++) {
		double left1 = cross(toVector(a, b), toVector(a, Q[i])), left2 = 0;
		if (i != (int) Q.size() - 1)
			left2 = cross(toVector(a, b), toVector(a, Q[i + 1]));
		if (left1 > -EPS)
			P.push_back(Q[i]); // Q[i] is on the left of ab
		if (left1 * left2 < -EPS) // edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
	}
	if (!P.empty()
			&& (fabs(P.back().x - P.front().x) > EPS
					|| fabs(P.back().y - P.front().y) > EPS))
		P.push_back(P.front()); // make P's first point = P's last point
	return P;
}

int main() {
	int N, W, H, x, y, count = 1;
	vector<point> P;

	while (scanf("%d %d %d %d %d", &N, &W, &H, &x, &y) != EOF) {
		P.clear();
		P.push_back(point(0, 0));
		P.push_back(point(W, 0));
		P.push_back(point(W, H));
		P.push_back(point(0, H));
		P.push_back(point(0, 0));
		point fountain(x, y);

		point p1, p2;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
			if (ccw(p1, p2, fountain))
				P = cutPolygon(p1, p2, P);
			else
				P = cutPolygon(p2, p1, P);
		}

		printf("Case #%d: %.3lf\n", count++, area(P));
	}
	return 0;
}
