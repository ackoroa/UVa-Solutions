#include <cstdio>
#include <map>
#include <cstring>
#include <cctype>
using namespace std;

map<char, int> freq;

int main() {
	char s[1000];
	int max;
	while (gets(s)) {
		freq.clear();
		max = -1;
		for (int i = 0; i < (int) strlen(s); i++) {
			if (isalpha(s[i])) {
				if (freq.count(s[i]) == 0)
					freq[s[i]] = 1;
				else
					freq[s[i]] = freq[s[i]] + 1;
				if (max < freq[s[i]])
					max = freq[s[i]];
			}
		}

		map<char, int>::iterator it;
		for (it = freq.begin(); it != freq.end(); it++) {
			if (it->second == max)
				printf("%c", it->first);
		}
		printf(" %d\n", max);

	}

	return 0;
}
