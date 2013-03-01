#include <cstdio>
#include <map>
#include <vector>
using namespace std;

vector<int> order;
map<int, int> freq;

int main() {
	int n;

	while (scanf("%d", &n) != EOF) {
		if (freq.count(n) == 0) {
			freq[n] = 1;
			order.push_back(n);
		} else
			freq[n] = freq[n] + 1;
	}

	for(int i=0;i<(int)order.size();i++){
		printf("%d %d\n",order[i], freq[order[i]]);
	}

	return 0;
}
