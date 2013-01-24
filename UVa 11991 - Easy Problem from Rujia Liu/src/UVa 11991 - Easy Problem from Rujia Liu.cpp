#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n, m, d, k;
	vector<vector<int> > v;
	while (scanf("%d %d", &n, &m) != EOF) {
		v.assign(1000000, vector<int>());

		for (int i = 1; i <= n; i++) {
			scanf("%d", &d);
			v[d].push_back(i);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &k, &d);

			if (k - 1 < v[d].size())
				printf("%d\n", v[d][k - 1]);
			else
				printf("0\n");
		}
	}

	return 0;
}
