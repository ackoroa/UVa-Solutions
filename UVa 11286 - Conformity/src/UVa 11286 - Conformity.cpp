#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n;

	while (cin >> n, n) {
		map<string, int> log;

		int maxN = -1;
		string x[5];

		for (int i = 0; i < n; i++) {
			cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
			sort(x, x + 5);

			string code;
			for (int j = 0; j < 5; j++) {
				code += x[j];
			}

			if (!log.count(code)) {
				log[code] = 1;
				maxN = max(maxN, 1);
			} else {
				int m = log[code] + 1;
				log[code] = m;
				maxN = max(maxN, m);
			}
		}

		int count = 0;
		map<string, int>::iterator it;
		for (it = log.begin(); it != log.end(); it++) {
			if (it->second == maxN)
				count += it->second;
		}

		printf("%d\n", count);
	}

	return 0;
}
