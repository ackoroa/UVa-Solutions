#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <map>
using namespace std;

class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
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
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};

map<string, int> nameMap;

int main() {
	int r, c, count;
	char s1[25], s2[25];
	string s1s, s2s;

	while (scanf("%d %d", &c, &r), c || r) {
		UFDS uf(c);
		nameMap.clear();
		count = 0;

		for (int i = 0; i < c; i++) {
			scanf("%s", s1);
			s1s = string(s1);

			if (!nameMap.count(s1s))
				nameMap[s1s] = count++;
		}

		int max = 1;
		for (int i = 0; i < r; i++) {
			scanf("%s %s", s1, s2);
			s1s = string(s1);
			s2s = string(s2);

			uf.unionSet(nameMap[s1s], nameMap[s2s]);
			if (uf.setSize(nameMap[s1]) > max)
				max = uf.setSize(nameMap[s1]);
		}

		printf("%d\n", max);
	}

	return 0;
}
