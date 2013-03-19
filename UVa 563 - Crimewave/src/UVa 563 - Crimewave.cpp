#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
	int to, from, ori, flow;
};
typedef vector<int> vi;

int mf, f, s, t;                          // global variables
vi p;
const int inf = 1 << 26;
edge edges[70004];
vector<vi> adj;
int e;

void addEdge(int a, int b, int capf, int capb) {
	edges[e].from = a;
	edges[e].to = b;
	edges[e].ori = capf;
	edges[e].flow = 0;
	adj[a].push_back(e); // adjlist points to an edge
	e++;
	edges[e].from = b;
	edges[e].to = a;
	edges[e].ori = capb;
	edges[e].flow = 0;
	adj[b].push_back(e);
	e++;
}

void augment(int v, int me) {
	if (v == s) {
		f = me;
		return;
	}
	if (p[v] != -1) {
		augment(edges[p[v]].from, min(me, edges[p[v]].ori - edges[p[v]].flow));
		edges[p[v]].flow += f;
		edges[p[v] ^ 1].flow -= f;
		// we add edges in pairs so x^1 will be the reverse of x
	}
}

int main() {
	int S, A, B, tc;

	//freopen("in.txt","r",stdin);

	scanf("%d", &tc);

	while (tc--) {
		scanf("%d %d %d", &S, &A, &B);

		e = 0;
		s = 0;
		t = 2 * (S * A) + 1;
		int V = t + 1;
		adj.assign(V, vi());
		int outF = S * A;

		// sides to sink
		for (int i = 1; i <= S; i++) {
			addEdge(i + outF, t, 1, 0);
			addEdge((S * (A - 1) + i) + outF, t, 1, 0);
		}
		for (int i = 1; i < A - 1; i++) {
			addEdge((i * S + 1) + outF, t, 1, 0);
			addEdge((i * S + S) + outF, t, 1, 0);
		}

		// in-vertex to out-vertex
		for (int i = 1; i <= S * A; i++) {
			addEdge(i, i + outF, 1, 0);
		}

		// source to bank
		for (int i = 0; i < B; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			addEdge(s, x + S * (y - 1), 1, 0);
		}

		// all nodes to its neighbour
		for (int i = 1; i <= S * A; i++) {
			//right
			if (i % S > 0)
				addEdge(i + outF, i + 1, 1, 0);
			//left
			if ((i - 1) % S > 0)
				addEdge(i + outF, i - 1, 1, 0);
			//down
			if (i + S <= S * A)
				addEdge(i + outF, i + S, 1, 0);
			//up
			if (i - S > 0)
				addEdge(i + outF, i - S, 1, 0);
		}

		// EK
		int mf = 0;
		while (1) {
			p.assign(V, -1);
			queue<int> q;
			q.push(s);
			p[s] = s;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < (int) adj[u].size(); i++) {
					edge ee = edges[adj[u][i]];
					if (ee.flow < ee.ori && p[ee.to] == -1) {
						p[ee.to] = adj[u][i]; // use edge to denote previous
						q.push(ee.to);
					}
				}
			}
			f = 0;
			augment(t, inf);
			if (!f)
				break;
			mf += f;
		}

		if (B == mf)
			printf("possible\n");
		else
			printf("not possible\n");
	}

	return 0;
}
