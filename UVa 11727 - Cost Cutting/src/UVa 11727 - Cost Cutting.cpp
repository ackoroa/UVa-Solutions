#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,cnt,a[3];

	cin >> n;

	cnt = 0;
	for(int i=0;i<n;i++){
		cnt++;
		cout << "Case " << cnt << ": ";

		cin >> a[0] >> a[1] >> a[2];
		vector<int> v(a,a+3);

		sort(v.begin(),v.end());

		cout << v[1] << endl;
	}

	return 0;
}
