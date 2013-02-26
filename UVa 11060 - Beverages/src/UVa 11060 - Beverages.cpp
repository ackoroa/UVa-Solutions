#include <cstdio>
#include <vector>
#include <bitset>
#include <map>
#include <utility>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> AdjList;
vi inDegree;
map<int, string> revNameMap;
map<string, int> nameMap;
bitset<105> visited;

int V, E;

bool contains(int u, int n) {
	for (int i = 0; i < (int) AdjList[u].size(); i++)
		if (AdjList[u][i] == n)
			return true;
	return false;
}

int main() {
	int cnt, count = 1;
	char name[55], n1[55], n2[55];

	while (scanf("%d", &V) != EOF) {
		cnt = 0;
		AdjList.assign(V, vi());
		inDegree.assign(V, 0);
		nameMap.clear();
		revNameMap.clear();
		for (int i = 0; i < 105; i++)
			visited.reset(i);

		for (int i = 0; i < V; i++) {
			scanf("%s", name);
			nameMap[string(name)] = cnt;
			revNameMap[cnt++] = string(name);
		}

		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			scanf("%s %s", n1, n2);
			if (!contains(nameMap[string(n1)], nameMap[string(n2)])) {
				AdjList[nameMap[string(n1)]].push_back(nameMap[string(n2)]);
				inDegree[nameMap[string(n2)]]++;
			}
		}

		printf("Case #%d: Dilbert should drink beverages in this order:",
				count++);
		bool done = false;
		while (!done) {
			done = true;
			for (int u = 0; u < V; u++) {
				if (inDegree[u] == 0 && !visited.test(u)) {
					done = false;
					visited.set(u);
					printf(" %s", revNameMap[u].data());
					for (int i = 0; i < (int) AdjList[u].size(); i++) {
						inDegree[AdjList[u][i]]--;
					}
					u = -1;
				}
			}
		}
		printf(".\n\n");
	}

	return 0;
}
