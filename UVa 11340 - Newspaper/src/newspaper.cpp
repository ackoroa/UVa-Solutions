#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n, k, m;
	int paychit[256];
	unsigned long long total;

	cin >> n;
	cin.ignore();
	for (; n > 0; n--) {
		total = 0;
		for (int i = 0; i < 256; i++) {
			paychit[i] = 0;
		}

		scanf("%d\n", &k);
		for (int i = 0; i < k; i++) {
			int p;
			unsigned char c;

			cin >> c >> p;
			cin.ignore();
			paychit[(int) c] = p;
		}

		cin >> m;
		cin.ignore();

		for (int i = 0; i < m; i++) {
			unsigned char c;
			while ((c = cin.get()) != '\n') {
				total += paychit[(int) c];
			}
		}

		printf("%.2lf$\n", total / 100.0);
	}

	return 0;
}
