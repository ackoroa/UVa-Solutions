#include <cstdio>
#include <vector>
#include <bitset>
#include <map>
#include <utility>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int m, n, totalWeight;
priority_queue<ii> pq;
vector<bool> taken;
vector<vii> AdjList;

void primproc(int u) {
	taken[u] = true;
	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (!taken[v.first])
			pq.push(ii(-v.second, -v.first));
	}
}

int main() {
	int u, v, w;

	while (scanf("%d %d", &m, &n), m || n) {
		totalWeight = 0;
		AdjList.assign(m, vii());

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
			totalWeight += w;
		}

		taken.assign(m, false);
		primproc(0);
		int mstCost = 0;
		while (!pq.empty()) {
			ii front = pq.top();
			pq.pop();
			u = -front.second, w = -front.first;
			if (!taken[u]) {
				mstCost += w;
				primproc(u);
			}
		}
		printf("%d\n", totalWeight - mstCost);
	}
	return 0;
}
