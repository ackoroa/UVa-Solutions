#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int AdjMat[105][105];

int main() {
	int tc;
	int n, e, t, m, u, v, w;

	scanf("%d", &tc);

	while (tc--) {
		scanf("%d\n%d\n%d\n%d\n", &n, &e, &t, &m);
		memset(AdjMat, 63, sizeof AdjMat);
		n++;

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			AdjMat[u][v] = w;
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					AdjMat[i][j] = min(AdjMat[i][j],
							AdjMat[i][k] + AdjMat[k][j]);

		int ans = 0;
		for (int i = 0; i < n; i++)
			if (AdjMat[i][e] <= t || (i == e))
				ans++;

		printf("%d\n", ans);
		if (tc)
			printf("\n");
	}

	return 0;
}
