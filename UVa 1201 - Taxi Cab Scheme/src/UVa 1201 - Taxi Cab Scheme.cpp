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
	int tc, V, VLeft;
	int n;
	int h, m;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);

		V = 2 * n;
		VLeft = n;
		AdjList.assign(V, vi());

		for (int i = 0; i < n; i++) {
			scanf("%d:%d %d %d %d %d", &h, &m, &sx[i], &sy[i], &dx[i], &dy[i]);
			time[i] = h * 60 + m;
			travelTime[i] = abs(sx[i] - dx[i]) + abs(sy[i] - dy[i]);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int transTime = abs(dx[i] - sx[j]) + abs(dy[i] - sy[j]);
				if (time[j] > time[i] + travelTime[i] + transTime) {
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

		printf("%d\n", n - MCBM);
	}
	return 0;
}
