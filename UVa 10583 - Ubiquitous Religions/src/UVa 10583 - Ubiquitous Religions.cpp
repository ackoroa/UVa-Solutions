#include <cstdio>
#include <vector>
#include <cstring>
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
	int numDisjointSets() {
		return numSets;
	}
};

int main() {
	int n, m, cnt = 1;
	int u, v;

	while (scanf("%d %d", &n, &m), n || m) {
		UFDS uf(n);

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			u--;
			v--;
			uf.unionSet(u, v);
		}

		printf("Case %d: %d\n", cnt++, uf.numDisjointSets());
	}

	return 0;
}
