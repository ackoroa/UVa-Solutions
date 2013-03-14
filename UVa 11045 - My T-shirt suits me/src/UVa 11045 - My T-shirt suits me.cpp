#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;

#define MAX_V 200
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v])); // recursive
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main() {
	int m, n, tc;
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d %d", &n, &m);
		memset(res, 0, sizeof res);

		for (int i = 1; i <= 6; i++) {
			res[0][i] = n / 6;
		}

		for (int i = 7; i < 7 + m; i++) {
			res[i][7 + m] = 1;
		}

		for (int i = 7; i < 7 + m; i++) {
			char s[4];
			scanf("%s", s);
			if (strcmp(s, "XXL") == 0)
				res[1][i] = 1;
			else if (strcmp(s, "XL") == 0)
				res[2][i] = 1;
			else if (strcmp(s, "L") == 0)
				res[3][i] = 1;
			else if (strcmp(s, "M") == 0)
				res[4][i] = 1;
			else if (strcmp(s, "S") == 0)
				res[5][i] = 1;
			else if (strcmp(s, "XS") == 0)
				res[6][i] = 1;
			scanf("%s", s);
			if (strcmp(s, "XXL") == 0)
				res[1][i] = 1;
			else if (strcmp(s, "XL") == 0)
				res[2][i] = 1;
			else if (strcmp(s, "L") == 0)
				res[3][i] = 1;
			else if (strcmp(s, "M") == 0)
				res[4][i] = 1;
			else if (strcmp(s, "S") == 0)
				res[5][i] = 1;
			else if (strcmp(s, "XS") == 0)
				res[6][i] = 1;
		}

		s = 0;
		t = 7 + m;

		mf = 0;
		while (1) {
			f = 0;
			vi dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < MAX_V; v++)
					if (res[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}

		if (m == mf)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
