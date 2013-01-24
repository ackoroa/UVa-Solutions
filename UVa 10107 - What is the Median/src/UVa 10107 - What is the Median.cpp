#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int d, n1, n2;
	vector<int> v;
	while (scanf("%d", &d) != EOF) {
		v.push_back(d);

		nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
		n1 = *(v.begin() + v.size() / 2);

		if (v.size() % 2 == 0) {
			nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());
			n2 = *(v.begin() + v.size() / 2 - 1);
			n1 = (n1 + n2) / 2;
		}

		printf("%d\n", n1);
	}

	return 0;
}
