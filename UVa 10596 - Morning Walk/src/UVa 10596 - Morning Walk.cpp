#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

vi deg;

int main() {
	int V, E, u, v;

	while (scanf("%d %d", &V, &E) != EOF) {
		deg.assign(V, 0);

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);
			deg[u]++;
			deg[v]++;
		}

		bool eul = true;
		for (int i = 0; i < V; i++) {
			if (deg[i] % 2 == 1 || deg[i] == 0) {
				eul = false;
				break;
			}
		}

		if (eul)
			printf("Possible\n");
		else
			printf("Not Possible\n");
	}

	return 0;
}
