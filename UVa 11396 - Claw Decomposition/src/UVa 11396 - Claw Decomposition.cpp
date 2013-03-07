#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;

int main() {
	int V, u, v;
	vector<vi> AdjList;

	while (scanf("%d", &V), V) {
		AdjList.assign(V, vi());

		while (scanf("%d %d", &u, &v), u || v) {
			AdjList[u - 1].push_back(v - 1);
			AdjList[v - 1].push_back(u - 1);
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
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
