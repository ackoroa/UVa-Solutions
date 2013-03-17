#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;

int main() {
	int tc;
	char c;
	int freq[26];
	priority_queue<pair<int, int> > pq;

	for (int i = 0; i < 26; i++) {
		freq[i] = 0;
	}

	scanf("%d", &tc);
	while (scanf("%c", &c) != EOF) {
		if (!isalpha(c))
			continue;

		freq[toupper(c) - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (freq[i] > 0)
			pq.push(make_pair(freq[i], -(i + 'A')));
	}

	while (!pq.empty()) {
		printf("%c %d\n", -pq.top().second, pq.top().first);
		pq.pop();
	}

	return 0;
}
