#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int AdjMat[105][105];
bool on[105];

int main() {
	int u, v, count = 1;

	while (true) {
		memset(AdjMat, 63, sizeof AdjMat);
		memset(on, false, sizeof on);

		scanf("%d %d", &u, &v);
		if (u == 0 && v == 0)
			break;

		while (true) {
			on[u] = true;
			on[v] = true;
			AdjMat[u][v] = 1;

			scanf("%d %d", &u, &v);
			if (u == 0 && v == 0)
				break;
		}

		for (int k = 0; k < 105; k++)
			for (int i = 0; i < 105; i++)
				for (int j = 0; j < 105; j++)
					AdjMat[i][j] = min(AdjMat[i][j],
							AdjMat[i][k] + AdjMat[k][j]);

		double ans = 0, nans = 0;
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 105; j++) {
				if (i == j)
					continue;
				if (on[i] && on[j]) {
					ans += AdjMat[i][j];
					nans++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3lf clicks\n",
				count++, ans / nans);
	}

	return 0;
}
