#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

class UFDS {
private:
	vector<int> p, rank, setSize;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSize.assign(N, 1);
	}

	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[findSet(x)] += setSize[findSet(y)];
			} else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
				setSize[findSet(y)] += setSize[findSet(x)];
			}
			numSets--;
		}
	}

	int nSets() {
		return numSets;
	}
};

double x[1005], y[1005];

double dist(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
	int tc, n, count = 1;
	double d;

	scanf("%d", &tc);

	while (tc--) {
		scanf("%d %lf", &n, &d);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &x[i], &y[i]);
		}

		UFDS us(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist(i, j) - d < 1e-8)
					us.unionSet(i, j);
			}
		}

		printf("Case %d: %d\n", count++, us.nSets());
	}

	return 0;
}
