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

ii strMatch() {
	int lo = 0, hi = n - 1, mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res >= 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (strncmp(T + SA[lo], P, m) != 0)
		return ii(-1, -1);
	ii ans;
	ans.first = lo;
	lo = 0;
	hi = n - 1;
	mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if (res > 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (strncmp(T + SA[hi], P, m) != 0)
		hi--;
	ans.second = hi;
	return ans;
}

void compLCP() {
	int i, L;
	phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		phi[SA[i]] = SA[i - 1];
	for (i = L = 0; i < n; i++) {
		if (phi[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while (T[i + L] == T[phi[i] + L])
			L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main() {
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", T);
		strcat(T, "$");
		n = strlen(T);
		makeSA();
		compLCP();

		int maximum = 0, maxidx = -1;
		for (int i = 0; i < n; i++) {
			if (LCP[i] > maximum) {
				maximum = LCP[i];
				maxidx = i;
			}
		}

		if (maxidx > -1) {
			strncpy(P, T + SA[maxidx], LCP[maxidx]);
			P[LCP[maxidx]] = '\0';
			m = strlen(P);
			ii pos = strMatch();
			printf("%s %d\n", P, pos.second - pos.first + 1);
		} else {
			printf("No repetitions found!\n");
		}
	}

	return 0;
}
