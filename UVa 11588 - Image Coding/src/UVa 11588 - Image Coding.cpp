#include <cstdio>
using namespace std;

int main() {
	int TC, r, c, m, n, count = 0;

	scanf("%d", &TC);

	while (TC--) {
		count++;
		scanf("%d %d %d %d", &r, &c, &m, &n);
		int total = r * c, freq[26];
		for (int i = 0; i < 26; i++) {
			freq[i] = 0;
		}

		for (int i = 0; i < total; i++) {
			char c;
			scanf("%c", &c);
			if (c != '\n')
				freq[c - 'A']++;
			else
				i--;
		}

		int max = -1;
		for (int i = 0; i < 26; i++) {
			if (freq[i] > max)
				max = freq[i];
		}
		int maxCount = 0;
		for (int i = 0; i < 26; i++) {
			if (freq[i] == max)
				maxCount++;
		}

		int ans = max * maxCount * m + (total - max * maxCount) * n;

		printf("Case %d: %d\n", count, ans);
	}

	return 0;
}
