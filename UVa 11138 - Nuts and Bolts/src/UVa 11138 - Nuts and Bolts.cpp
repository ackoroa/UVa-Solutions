#include <cstdio>
#include <vector>
#include <cstring>
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

int main() {
	int tc, V, VLeft, caseno = 1;
	int nuts, bolts;
	int fits;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &bolts, &nuts);
		V = bolts + nuts;
		VLeft = bolts;
		AdjList.assign(V, vi());

		for (int b = 0; b < bolts; b++) {
			for (int n = 0; n < nuts; n++) {
				scanf("%d", &fits);
				if (fits)
					AdjList[b].push_back(n + bolts);
			}
		}

		int MCBM = 0;
		match.assign(V, -1);

		for (int l = 0; l < VLeft; l++) {
			vis.assign(VLeft, 0);
			MCBM += Aug(l);
		}

		printf("Case %d: ", caseno++);
		printf("a maximum of %d nuts and bolts ", MCBM);
		printf("can be fitted together\n");
	}
	return 0;
}
