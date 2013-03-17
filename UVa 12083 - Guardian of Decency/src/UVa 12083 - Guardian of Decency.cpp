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
	int tc, n, male;
	int height[505];
	char sex[505], music[505][101], sport[505][101];

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		AdjList.assign(n, vi());

		male = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %c %s %s", &height[i], &sex[i], music[i], sport[i]);
			if (sex[i] == 'M')
				male++;
		}

		int midx = 0;
		for (int i = 0; i < n; i++) {
			if (sex[i] == 'M') {
				int fidx = male;
				for (int j = 0; j < n; j++) {
					if (sex[j] == 'F') {
						if (abs(height[i] - height[j]) <= 40
								&& strcmp(music[i], music[j]) == 0
								&& strcmp(sport[i], sport[j]) != 0) {
							AdjList[midx].push_back(fidx);
						}
						fidx++;
					}
				}
				midx++;
			}
		}

		int MCBM = 0;
		match.assign(n, -1);

		for (int l = 0; l < male; l++) {
			vis.assign(male, 0);
			MCBM += Aug(l);
		}

		printf("%d\n", n - MCBM);
	}
	return 0;
}
