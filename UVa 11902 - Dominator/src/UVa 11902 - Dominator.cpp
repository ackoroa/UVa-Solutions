#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

int V, tc, count = 1;
vector<vi> AdjList;
bitset<105> initVisited, curVisited;
bool first;

void dfs(int u, int del) {
	bitset<105> *visited;
	if (first)
		visited = &initVisited;
	else
		visited = &curVisited;

	visited->set(u);
	if (u == del)
		return;

	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!visited->test(v))
			dfs(v, del);
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &V);
		AdjList.assign(V, vi());
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				int e;
				scanf("%d", &e);
				if (e)
					AdjList[i].push_back(j);
			}
		}

		first = true;
		for (int i = 0; i < V; i++)
			initVisited.reset(i);
		dfs(0, V);
		first = false;

		printf("Case %d:", count++);
		for (int i = 0; i < V; i++) {
			for (int k = 0; k < V; k++)
				curVisited.reset(k);
			dfs(0, i);

			printf("\n+");
			for (int j = 0; j < V * 2 - 1; j++) {
				printf("-");
			}
			printf("+\n|");
			for (int j = 0; j < V; j++) {
				if (initVisited.test(j) && (i == j || !curVisited.test(j)))
					printf("Y");
				else
					printf("N");
				printf("|");
			}
		}
		printf("\n+");
		for (int j = 0; j < V * 2 - 1; j++) {
			printf("-");
		}
		printf("+\n");
	}

	return 0;
}
