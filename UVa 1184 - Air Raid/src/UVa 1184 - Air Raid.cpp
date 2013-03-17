#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;

vi match, vis; // global variables
vector<vi> AdjList;

int Aug(int l) { // return 1 if there exists an augmenting path
	if (vis[l])
		return 0; // return 0 otherwise
	vis[l] = 1;
	for (int j = 0; j < (int) AdjList[l].size(); j++) {
		int r = AdjList[l][j];
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1; // found 1 matching
		}
	}
	return 0; // no matching
}

int sx[505], sy[505], dx[505], dy[505], travelTime[505], time[505];

int main() {
	int tc, V, VLeft, E;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d\n%d", &V, &E);

		VLeft = V;
		AdjList.assign(V, vi());

		for(int i=0;i<E;i++){
			int u,v;
			scanf("%d %d",&u, &v);
			u--;v--;
			AdjList[u].push_back(v);
		}

		int MCBM = 0;
		match.assign(V, -1);

		for (int l = 0; l < VLeft; l++) {
			vis.assign(VLeft, 0);
			MCBM += Aug(l);
		}

		printf("%d\n", V - MCBM);
	}
	return 0;
}
