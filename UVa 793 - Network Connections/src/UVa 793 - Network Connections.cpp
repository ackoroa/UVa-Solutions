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
	int tc, n, yes, no;
	char line[1000], q;
	int c1, c2;

	scanf("%d\n", &tc);
	while (tc--) {
		yes = no = 0;
		scanf("%d\n\n", &n);
		UFDS set(n);

		while (true) {
			gets(line);
			if (strcmp(line, "") == 0 || feof(stdin)) break;
			sscanf(line, "%c %d %d", &q, &c1, &c2);
			c1--;
			c2--;
			if (q == 'c') {
				set.unionSet(c1, c2);
			} else if (q == 'q') {
				if (set.isSameSet(c1, c2))
					yes++;
				else
					no++;
			}
		}

		printf("%d,%d\n", yes, no);
		if (tc)
			printf("\n");
	}

	return 0;
}
