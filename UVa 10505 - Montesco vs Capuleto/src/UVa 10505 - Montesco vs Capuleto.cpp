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
	int V, E, v, tc;
	vector<vi> AdjList;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &V);
		AdjList.assign(V, vi());

		for (int u = 0; u < V; u++) {
			scanf("%d", &E);
			for (int j = 0; j < E; j++) {
				scanf("%d", &v);
				v--;
				if (v < V) {
					if (!has(AdjList[u], v))
						AdjList[u].push_back(v);
					if (!has(AdjList[v], u))
						AdjList[v].push_back(u);
				}
			}
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

			if (isBipartite)
				ans += max(colorCount[0], colorCount[1]);
		}

		printf("%d\n", ans);
	}

	return 0;
}
