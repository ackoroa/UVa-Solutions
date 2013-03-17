#include <cstdio>
#include <vector>
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
	int tc, V, VLeft, count = 1;
	int n, m;
	int a[105], b[105];

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &b[i]);
		}

		V = n + m;
		VLeft = n;
		AdjList.assign(V, vi());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] != 0) {
					if (b[j] == 0 || b[j] % a[i] == 0)
						AdjList[i].push_back(j + n);
				} else if (a[i] == 0 && b[j] == 0) {
					AdjList[i].push_back(j + n);
				}
			}
		}

		int MCBM = 0;
		match.assign(V, -1);

		for (int l = 0; l < VLeft; l++) {
			vis.assign(VLeft, 0);
			MCBM += Aug(l);
		}

		printf("Case %d: %d\n", count++, MCBM);
	}
	return 0;
}
