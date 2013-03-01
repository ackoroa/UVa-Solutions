#include <cstdio>
#include <map>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int AdjMat[55][55];
map<string, int> pplIdx;
int P, R;

int main() {
	char n1[100], n2[100];
	string n1s, n2s;
	int count = 1;

	while (scanf("%d %d", &P, &R), P || R) {
		pplIdx.clear();
		memset(AdjMat, 32, sizeof AdjMat);
		int idx = 0;

		for (int i = 0; i < R; i++) {
			scanf("%s", n1);
			scanf("%s", n2);
			n1s = string(n1);
			n2s = string(n2);

			if (pplIdx.count(n1s) == 0) {
				pplIdx[n1s] = idx++;
			}
			if (pplIdx.count(n2s) == 0) {
				pplIdx[n2s] = idx++;
			}

			AdjMat[pplIdx[n1s]][pplIdx[n2s]] = 1;
			AdjMat[pplIdx[n2s]][pplIdx[n1s]] = 1;
		}

		for (int k = 0; k < P; k++)
			for (int i = 0; i < P; i++)
				for (int j = 0; j < P; j++)
					AdjMat[i][j] = min(AdjMat[i][j],
							AdjMat[i][k] + AdjMat[k][j]);

		int maximum = -1;
		printf("Network %d: ", count++);
		for (int i = 0; i < P; i++) {
			for (int j = i + 1; j < P; j++) {
				maximum = max(maximum, AdjMat[i][j]);
			}
		}
		if (maximum > 5e8)
			printf("DISCONNECTED\n\n");
		else
			printf("%d\n\n", maximum);
	}

	return 0;
}
