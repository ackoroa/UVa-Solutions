#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

typedef vector<int> vi;

#define INF 1e9
#define MAX_V 105

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vi> AdjList;
vi p;

int m, w, V;

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
	while (scanf("%d %d", &m, &w), m || w) {
		V = m * 2 - 2;
		memset(res, 0, sizeof res);
		AdjList.assign(V, vi());

		s = 0;
		t = V - 1;

		for (int i = 0; i < m - 2; i++) {
			int id, c, u, v;
			scanf("%d %d", &id, &c);
			id--;
			u = id + id - 1;
			v = u + 1;

			res[u][v] = c;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		for (int i = 0; i < w; i++) {
			int id1, id2, c, u1, u2, v1, v2;
			scanf("%d %d %d", &id1, &id2, &c);
			id1--;
			id2--;

			if (id1 != 0 && id1 != m - 1) {
				u1 = id1 + id1 - 1;
				v1 = u1 + 1;
			} else {
				if (id1 == 0)
					u1 = v1 = 0;
				else
					u1 = v1 = V - 1;
			}

			if (id2 != 0 && id2 != m - 1) {
				u2 = id2 + id2 - 1;
				v2 = u2 + 1;
			} else {
				if (id2 == 0)
					u2 = v2 = id2;
				else
					u2 = v2 = V - 1;
			}

			res[v1][u2] = c;
			res[v2][u1] = c;
			AdjList[v1].push_back(u2);
			AdjList[u2].push_back(v1);
			AdjList[v2].push_back(u1);
			AdjList[u1].push_back(v2);
		}

		EdmondKarps();
		printf("%d\n", mf);
	}

	return 0;
}
