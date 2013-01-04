#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, b, h, w;
	int p, nb, minCost;

	while (scanf("%d %d %d %d\n", &n, &b, &h, &w) != EOF) {
		minCost = 2000000000;
		while (h--) {
			cin >> p;
			for(int i=0;i<w;i++) {
				cin >> nb;
				if (nb >= n) {
					minCost = min(minCost,n * p);
					string s;
					getline(cin, s);
					break;
				}
			}
		}
		if (minCost != 2000000000 && minCost <= b)
			cout << minCost << endl;
		else
			cout << "stay home" << endl;
	}

	return 0;
}
