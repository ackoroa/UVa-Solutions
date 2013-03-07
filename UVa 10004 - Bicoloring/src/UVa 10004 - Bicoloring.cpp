#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;

int main() {
	int V, E, u, v;
	vector<vi> AdjList;

	while (scanf("%d", &V), V) {
		AdjList.assign(V, vi());
		scanf("%d", &E);

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		queue<int> q;
		q.push(0);
		vi color(V, 1e9);
		color[0] = 0;
		bool isBipartite = true;
		while (!q.empty() && isBipartite) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < (int) AdjList[u].size(); j++) {
				int v = AdjList[u][j];
				if (color[v] == 1e9) {
					color[v] = 1 - color[u];
					q.push(v);
				} else if (color[v] == color[u]) {
					isBipartite = false;
					break;
				}
			}
		}

		if (isBipartite)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

	return 0;
}
