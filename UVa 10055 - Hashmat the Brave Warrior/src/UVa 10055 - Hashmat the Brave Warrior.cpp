#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long unsigned a, b;
	while (cin >> a >> b) {
		cout << max(a, b) - min(a, b) << "\n";
	}
	return 0;
}
