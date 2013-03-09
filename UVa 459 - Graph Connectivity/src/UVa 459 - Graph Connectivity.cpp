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
	int tc;
	char u, v, s[5];

	scanf("%d\n\n", &tc);
	while (tc--) {
		gets(s);
		sscanf(s, "%c", &v);
		UFDS uf(v - 'A' + 1);

		while (gets(s) && strcmp(s, "") != 0) {
			sscanf(s, "%c%c", &u, &v);
			uf.unionSet(u - 'A', v - 'A');
		}
		printf("%d\n", uf.numDisjointSets());
		if (tc)
			printf("\n");
	}

	return 0;
}
