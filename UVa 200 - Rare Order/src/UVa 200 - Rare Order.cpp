#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
bitset<30> visited, appeared;
vi finishOrder;

void dfs(int u) {
	visited.set(u);

	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}

	finishOrder.push_back(u);
}

int main() {
	char s[25], ps[25];
	AdjList.assign(30, vi());

	scanf("%s", ps);
	while (scanf("%s", s), strcmp(s, "#") != 0) {
		for (int i = 0; i < (int) strlen(s) && i < (int) strlen(ps); i++) {
			if (ps[i] != s[i]) {
				appeared.set(ps[i] - 'A');
				appeared.set(s[i] - 'A');
				AdjList[ps[i] - 'A'].push_back(s[i] - 'A');
				break;
			}
		}
		strcpy(ps, s);
	}

	for (int i = 0; i < 26; i++) {
		if (!visited[i] && appeared[i])
			dfs(i);
	}

	for (int i = finishOrder.size() - 1; i >= 0; i--) {
		printf("%c", finishOrder[i] + 'A');
	}
	printf("\n");

	return 0;
}
