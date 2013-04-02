#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;

static int WHITE = 0;
static int BLACK = 1;

bitset<110> colored;
int color[110];
vector<vi> AdjList;
int tc, n, k, ans;
vi ansls;

void solve(int u) {
	if (u == n) {
		int b = 0, w = 0;
		for (int i = 0; i < n; i++) {
			if (color[i] == BLACK)
				b++;
			else
				w++;
		}
		if (b > ans) {
			ans = b;
			ansls.clear();
			for (int i = 0; i < n; i++) {
				if (color[i] == BLACK)
					ansls.push_back(i);
			}
		}
		return;
	}

	bool canBlack = true;

	//check allowed color
	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (colored[v] && color[v] == BLACK) {
			canBlack = false;
			break;
		}
	}

	colored.set(u);
	if (canBlack) {
		color[u] = BLACK;
		solve(u + 1);
	}
	color[u] = WHITE;
	solve(u + 1);
	colored.reset(u);
}

int main() {
	int u, v;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);

		AdjList.assign(n, vi());
		colored.reset();
		ans = -1;
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &u, &v);
			u--;
			v--;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		solve(0);

		printf("%d\n", ans);
		for (int i = 0; i < (int) ansls.size(); i++) {
			printf("%d", ansls[i] + 1);
			if (i < (int) ansls.size() - 1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
