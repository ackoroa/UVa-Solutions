#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define INF 1e9
#define EPS 1e-11
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
	bool operator <(point other) const;
};
point ORIGIN = point(0, 0);

class xycomp {
public:
	bool operator()(const point &p1, const point &p2) const {
		if (fabs(p1.x - p2.x) > EPS)
			return p1.x > p2.x;
		return p1.y > p2.y;
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
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

bool ccw(point p, point q, point r) {
	return cross(toVector(p, q), toVector(p, r)) > 0;
}

bool point::operator<(point other) const {
	double angleThis = angle(*this, ORIGIN, point(1, 0));
	//angleThis *= ccw(*this, ORIGIN, point(INF, 0)) ? 1 : -1;
	double angleOther = angle(other, ORIGIN, point(1, 0));
	//angleOther *= ccw(*this, ORIGIN, point(INF, 0)) ? 1 : -1;
	if (fabs(angleThis - angleOther) > EPS) {
		return angleThis < angleOther;
	}
	return dist(*this, ORIGIN) < dist(other, ORIGIN);
}

int n, x, y, z;
pair<point, int> poles[100010];
int maxH;

int main() {
	int count = 1;

	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			poles[i] = make_pair(point(x, y), z);
		}

		sort(poles, poles + n);

		priority_queue<point, vector<point>, xycomp> pq;
		double curAngle = angle(poles[0].first, ORIGIN, point(INF, 0));
		curAngle *= ccw(poles[0].first, ORIGIN, point(INF, 0)) ? 1 : -1;
		maxH = poles[0].second;
		for (int i = 1; i < n; i++) {
			double tAngle = angle(poles[i].first, ORIGIN, point(INF, 0));
			tAngle *= ccw(poles[i].first, ORIGIN, point(INF, 0)) ? 1 : -1;
			if (fabs(curAngle - tAngle) < EPS) {
				if (poles[i].second <= maxH) {
					pq.push(poles[i].first);
				} else {
					maxH = poles[i].second;
				}
			} else {
				curAngle = tAngle;
				maxH = poles[i].second;
			}
		}

		printf("Data set %d:\n", count++);
		if (pq.empty()) {
			printf("All the lights are visible.\n");
		} else {
			printf("Some lights are not visible:\n");
			while (!pq.empty()) {
				printf("x = %.0lf, y = %.0lf", pq.top().x, pq.top().y);
				pq.pop();
				if (pq.empty())
					printf(".\n");
				else
					printf(";\n");
			}
		}
	}

	return 0;
}
