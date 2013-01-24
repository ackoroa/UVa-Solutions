#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > AdjList;
int x[30000];
bool visited[30000];
queue<int> bfsQ;

int main() {
	int n, m, k, s;

	while (scanf("%d %d", &n, &m), n || m) {
		AdjList.assign(n, vector<int>());
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &k);
			for (int j = 0; j < k; j++) {
				scanf("%d", &x[j]);
			}

			for (int j = 0; j < k; j++) {
				for (int l = 0; l < k; l++) {
					if (j != l)
						AdjList[x[j]].push_back(x[l]);
				}
			}
		}

		bfsQ.push(0);
		visited[0] = true;
		int ans = 0;
		while (!bfsQ.empty()) {
			s = bfsQ.front();
			bfsQ.pop();
			ans++;

			for (int i = 0; i < AdjList[s].size(); i++) {
				if (!visited[AdjList[s].at(i)]) {
					visited[AdjList[s].at(i)] = true;
					bfsQ.push(AdjList[s].at(i));
				}
			}
		}

		printf("%d\n", ans);
	}
}
