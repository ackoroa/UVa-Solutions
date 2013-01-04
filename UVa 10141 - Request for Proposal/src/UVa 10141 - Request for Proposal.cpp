#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	int r, n;
	string x;
	int count = 0;

	while (cin >> r >> n, r || n) {
		count++;

		double price = 2000000000, p;
		int reqMet = -1, rm;
		string name, nam;

		for (int i = 0; i < r; i++) {
			cin.ignore();
			getline(cin, x);
		}

		while (n--) {
			getline(cin,nam);
			scanf("%lf %d\n", &p, &rm);
			if (rm > reqMet) {
				reqMet = rm;
				name = nam;
				price = p;
			} else if (rm == reqMet && p < price) {
				reqMet = rm;
				name = nam;
				price = p;
			}

			for (int i = 0; i < rm; i++) {
				getline(cin, x);
			}
		}

		if (count > 1)
			cout << endl;
		cout << "RFP #" << count << endl;
		cout << name << endl;
	}

	return 0;
}
