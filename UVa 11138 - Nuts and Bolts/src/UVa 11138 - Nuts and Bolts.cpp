// just in case I need it :D

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

typedef vector<int> vi;

#define MAXV 1001
#define INF 1e9

vector<vi> AdjList;
vi match, dist;
int V, VLeft;

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= VLeft; i++) {
		if (match[i] == 0) {
			dist[i] = 0;
			q.push(i);
		} else
			dist[i] = INF;
	}
	dist[0] = INF;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u != 0) {
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (dist[match[v]] == INF) {
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return (dist[0] != INF);
}

bool dfs(int u) {
	if (u != 0) {
		for (int i = 0; i < (int) AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			if (dist[match[v]] == dist[u] + 1) {
				if (dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopkarp() {
	match.assign(V, 0);
	dist.assign(V, 0);
	int matching = 0, i;
	while (bfs())
		for (i = 1; i <= VLeft; i++)
			if (match[i] == 0 && dfs(i))
				matching++;
	return matching;
}

int main() {
	int tc, caseno = 1;
	int nuts, bolts;
	int fits;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &bolts, &nuts);
		V = bolts + nuts + 1;
		VLeft = bolts;
		AdjList.assign(V, vi());

		for (int b = 1; b <= bolts; b++) {
			for (int n = 1; n <= nuts; n++) {
				scanf("%d", &fits);
				if (fits)
					AdjList[b].push_back(n + bolts);
			}
		}

		int MCBM = hopkarp();

		printf("Case %d: ", caseno++);
		printf("a maximum of %d nuts and bolts ", MCBM);
		printf("can be fitted together\n");
	}
	return 0;
}
