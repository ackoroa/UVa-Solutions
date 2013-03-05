#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int main() {
	int tc;
	int canN, voteN;
	char can[84], par[84];
	string s;

	scanf("%d", &tc);
	while (tc--) {
		map<string, pair<int, string> > m;
		scanf("%d\n", &canN);
		for (int i = 0; i < canN; i++) {
			gets(can);
			gets(par);
			m[string(can)] = pair<int, string>(0, string(par));
		}
		scanf("%d\n", &voteN);
		for (int i = 0; i < voteN; i++) {
			gets(can);
			s = string(can);
			if (m.count(s))
				m[s] = pair<int, string>(m[s].first + 1, m[s].second);
		}

		int max = -1, maxn = 0;
		string ans = "";
		map<string, pair<int, string> >::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second.first > max) {
				max = it->second.first;
				maxn = 1;
				ans = it->second.second;
			} else if (it->second.first == max) {
				maxn++;
			}
		}

		if (maxn > 1 || maxn < 0) {
			printf("tie\n");
		} else {
			printf("%s\n", ans.data());
		}
		if (tc)
			printf("\n");
	}

	return 0;
}
