#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

vector<vector<int> > AdjList;
vector<int> hamilPath;
bitset<300> visited;
bool hamil;
int n, u1, u2;

void recBFS(int u, int pathLen) {
	visited.set(u);

	if (hamil)
		return;
	if (pathLen == n -1) {
		for (int i = 0; i < AdjList[u].size(); i++) {
			if (AdjList[u].at(i) == 1) {
				hamil = true;
				return;
			}
		}
	}

	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u].at(i);
		if (!visited.test(v)) {
			hamilPath.push_back(v);
			recBFS(v, pathLen + 1);
		}
		if(hamil) return;
	}
	hamilPath.pop_back();
	visited.reset(u);
}

int main() {
	char line[20];

	while (scanf("%d", &n) != EOF) {
		AdjList.assign(n + 1, vector<int>());
		for (int i = 0; i < 300; i++)
			visited.reset(i);
		hamil = false;
		hamilPath.clear();

		while (gets(line), strcmp(line, "%")) {
			sscanf(line, "%d %d", &u1, &u2);

			AdjList[u1].push_back(u2);
			AdjList[u2].push_back(u1);
		}

		hamilPath.push_back(1);
		recBFS(1, 0);

		if(!hamil) printf("N\n");
		else{
			for(int i=0;i<hamilPath.size();i++){
				printf("%d ",hamilPath.at(i));
			}
			printf("1\n");
		}
	}

	return 0;
}
