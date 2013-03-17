#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adj, tadj;

int main() {
	int m, n;
	int pos[1001], num[1001];

	while (scanf("%d %d", &m, &n) != EOF) {
		adj.assign(m, vii());
		tadj.assign(n, vii());
		for (int i = 0; i < m; i++) {
			int nr;
			scanf("%d", &nr);

			for (int j = 0; j < nr; j++) {
				scanf("%d", &pos[j]);
			}
			for (int j = 0; j < nr; j++) {
				scanf("%d", &num[j]);
			}
			for (int j = 0; j < nr; j++) {
				adj[i].push_back(ii(pos[j] - 1, num[j]));
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < (int) adj[i].size(); j++) {
				ii v = adj[i][j];
				tadj[v.first].push_back(ii(i, v.second));
			}
		}

		printf("%d %d\n", n, m);
		for (int i = 0; i < n; i++) {
			printf("%d", tadj[i].size());
			for (int j = 0; j < (int) tadj[i].size(); j++) {
				printf(" %d", tadj[i][j].first + 1);
			}
			printf("\n");
			for (int j = 0; j < (int) tadj[i].size(); j++) {
				printf("%d", tadj[i][j].second);
				if (j < (int) tadj[i].size() - 1)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
