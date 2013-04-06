#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

#define MAXN 100010
char T[MAXN], P[MAXN];
int n, m;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN], phi[MAXN];
int LCP[MAXN], PLCP[MAXN];

void countSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void makeSA() {
	int i, k, r;
	for (i = 0; i < n; i++) {
		RA[i] = T[i];
		SA[i] = i;
	}
	for (k = 1; k < n; k <<= 1) {
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =
					(RA[SA[i]] == RA[SA[i - 1]]
							&& RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
	}
}

int main() {
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", P);
		m = strlen(P);
		T[0] = '\0';
		strcat(T, P);
		strcat(T, P);
		strcat(T, "{");
		n = strlen(T);
		makeSA();

		for (int i = 0; i <= n; i++) {
			if (SA[i] < m) {
				printf("%d\n", SA[i] + 1);
				break;
			}
		}
	}

	return 0;
}
