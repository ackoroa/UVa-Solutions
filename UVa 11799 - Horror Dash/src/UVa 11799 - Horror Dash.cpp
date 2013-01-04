#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int TC,n,x,maxS;

	cin >> TC;
	for(int i=0;i<TC;i++){
		cin >> n;
		maxS = -1;
		while(n--){
			cin >> x;
			maxS = max(maxS,x);
		}
		cout << "Case " << i+1 << ": " << maxS << endl;
	}

	return 0;
}
