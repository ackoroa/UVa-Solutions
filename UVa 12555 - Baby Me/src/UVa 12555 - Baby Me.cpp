#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int tc, a, b, count = 1;

	cin >> tc;
	while (tc--) {
		cin >> a >> s;
		b = s.length() > 3 ? (int) s[3] - '0' : 0;
		cout << "Case " << count++ << ": " << a * 0.5 + b * 0.05 << endl;
	}

	return 0;
}
