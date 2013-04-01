#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
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
	int matching = 0;
	while (bfs())
		for (int i = 1; i <= VLeft; i++)
			if (match[i] == 0 && dfs(i))
				matching++;
	return matching;
}

int main() {
	int n, MCBM;
	int ux[30], uy[30], dx[30], dy[30];
	int x[30], y[30], cnt = 1;
	map<int, int> dict;

	while (scanf("%d", &n), n) {
		dict.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d %d", &ux[i], &dx[i], &uy[i], &dy[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		//node from 1 to V. 0 reserved
		V = 2 * n + 1;
		VLeft = n;
		AdjList.assign(V, vi());

		for (int sheet = 1; sheet <= n; sheet++) {
			for (int number = 1; number <= n; number++) {
				if (x[number] < dx[sheet] && x[number] > ux[sheet]
						&& y[number] > uy[sheet] && y[number] < dy[sheet]) {
					AdjList[sheet].push_back(number + n);
				}
			}
		}

		for (int sheet = 1; sheet <= n; sheet++) {
			for (int j = 0; j < (int) AdjList[sheet].size(); j++) {
				int number = AdjList[sheet][0];
				AdjList[sheet].erase(AdjList[sheet].begin());
				MCBM = hopkarp();
				if (MCBM != n) {
					dict[sheet] = number;
				}
				AdjList[sheet].push_back(number);
			}
		}

		printf("Heap %d\n", cnt++);
		if (dict.size() == 0) {
			printf("none\n");
		} else {
			map<int, int>::iterator it = dict.begin();
			while (it != dict.end()) {
				printf("(%c,%d)", it->first + 'A' - 1, it->second - n);
				it++;
				if (it != dict.end())
					printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
