#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000001

char T[MAXN], P[MAXN];
int b[MAXN], n, m, anslen;

void kmpPreProc() {
	m = strlen(P);
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}

void kmp() {
	n = strlen(T);
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j])
			j = b[j];
		i++;
		j++;
		if (j > anslen)
			anslen = j;
		if (j == m) {
			j = b[j];
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		scanf("%s", P);
		int len = strlen(P);
		for (int i = 0; i < len; i++) {
			T[i] = P[len - i - 1];
		}
		T[len] = '\0';

		kmpPreProc();
		anslen = -1;
		kmp();
		for (int i = anslen - 1; i >= 0; i--) {
			printf("%c", P[i]);
		}
		printf("\n");
	}

	return 0;
}
