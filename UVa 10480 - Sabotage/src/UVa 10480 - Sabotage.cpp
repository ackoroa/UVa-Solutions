#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define MAX_V 55

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vi> AdjList;
vi p;

int n, m, cnt = 1;

bitset<MAX_V> dfsv;
set<int> SSet;

void dfs(int u) {
	dfsv.set(u);
	SSet.insert(u);
	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!dfsv.test(v) && res[u][v] > 0) {
			dfs(v);
		}
	}
}

void mincut() {
	SSet.clear();
	for (int i = 0; i < MAX_V; i++)
		dfsv.reset();
	dfs(s);
	set<int>::iterator it;

	for (it = SSet.begin(); it != SSet.end(); it++) {
		int u = *it;
		for (int i = 0; i < (int) AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			if (SSet.count(v))
				continue;
			if (res[u][v] <= 0) {
				printf("%d %d\n", u + 1, v + 1);
			}
		}
	}
	printf("\n");
}

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void EdmondKarps() {
	mf = 0;
	while (1) {
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)
			break;
		mf += f;
	}
}

int main() {
	while (scanf("%d %d", &n, &m), n || m) {
		memset(res, 0, sizeof res);
		AdjList.assign(n, vi());

		s = 0;
		t = 1;

		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			res[u][v] += w;
			res[v][u] += w;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		EdmondKarps();
		mincut();
	}

	return 0;
}
