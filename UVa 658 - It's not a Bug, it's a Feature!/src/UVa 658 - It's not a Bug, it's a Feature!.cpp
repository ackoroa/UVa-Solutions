#include<cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

queue<int> bfsq;
bitset<1050000> visited;
char reqs[100][21], fixs[100][21];
int t[100], n, m;

bool matchReq(int u, int j) {
	for (int i = 0; i < n; i++) {
		if (reqs[j][i] == '+' && !(1 & (u >> (n - i - 1))))
			return false;
		if (reqs[j][i] == '-' && (1 & (u >> (n - i - 1))))
			return false;
	}
	return true;
}

int applyPatch(int u, int j) {
	int v = 0;
	for (int i = 0; i < n; i++) {
		if (fixs[j][i] == '+')
			v += 1;
		else if (fixs[j][i] == '0')
			v += 1 & (u >> (n - i - 1));
		v <<= 1;
	}
	v >>= 1;
	return v;
}

int main(void) {
	int count = 0;
	while (scanf("%d %d", &n, &m), n || m) {
		count++;
		printf("Product %d\n", count);

		for (int i = 0; i < m; i++) {
			scanf("%d %s %s", &t[i], reqs[i], fixs[i]);
		}

		vi dist(1 << n, 1e9);
		dist[(1 << n) - 1] = 0;
		priority_queue<ii, vii, greater<ii> > pq;
		pq.push(ii(0, (1 << n) - 1));

		while (!pq.empty()) {
			ii front = pq.top();
			pq.pop();
			int d = front.first, u = front.second;
			if (d == dist[u]) {
				for (int j = 0; j < m; j++) {
					if (matchReq(u, j)) {
						int v = applyPatch(u, j), vd = t[j];
						if (dist[u] + vd < dist[v]) {
							dist[v] = dist[u] + vd;
							pq.push(ii(dist[v], v));
						}
					}
				}
			}
		}

		if (dist[0] == 1e9)
			printf("Bugs cannot be fixed.\n\n");
		else
			printf("Fastest sequence takes %d seconds.\n\n", dist[0]);
	}

	return 0;
}
