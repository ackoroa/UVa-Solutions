#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
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

int money[10005];
map<int,int> calc;

int main() {
	int n, m, tc;
	int u, v;

	scanf("%d",&tc);
	while (tc--) {
		scanf("%d %d",&n,&m);
		UFDS uf(n);
		calc.clear();

		for(int i=0;i<n;i++){
			scanf("%d",&money[i]);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			uf.unionSet(u, v);
		}

		for(int i=0;i<n;i++){
			if(calc.count(uf.findSet(i))==0){
				calc[uf.findSet(i)] = money[i];
			}
			else{
				calc[uf.findSet(i)] += money[i];
			}
		}

		bool can = true;
		map<int,int>::iterator it;
		for(it = calc.begin();it != calc.end();it++){
			if(it->second != 0) can = false;
		}

		if(can) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}
