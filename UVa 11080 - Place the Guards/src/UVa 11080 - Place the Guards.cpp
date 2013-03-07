#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

bool has(vi v, int e) {
	for (int i = 0; i < (int) v.size(); i++)
		if (v[i] == e)
			return true;
	return false;
}

int main() {
	int V, E, u, v, tc;
	vector<vi> AdjList;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &V, &E);
		AdjList.assign(V, vi());

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		vi color(V, 1e9);
		bool isBipartite;
		int ans = 0;

		for (int s = 0; s < V; s++) {
			if (color[s] != 1e9)
				continue;

			isBipartite = true;
			int colorCount[2] = { 0, 0 };
			queue<int> q;
			q.push(s);
			color[s] = 0;
			colorCount[0]++;

			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < (int) AdjList[u].size(); j++) {
					int v = AdjList[u][j];
					if (color[v] == 1e9) {
						color[v] = 1 - color[u];
						colorCount[color[v]]++;
						q.push(v);
					} else if (color[v] == color[u]) {
						isBipartite = false;
					}
				}
			}

			if (isBipartite) {
				ans += (colorCount[0] > 0 && colorCount[1] > 0) ?
						min(colorCount[0], colorCount[1]) :
						max(colorCount[0], colorCount[1]);
			} else {
				ans = -1;
				break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
