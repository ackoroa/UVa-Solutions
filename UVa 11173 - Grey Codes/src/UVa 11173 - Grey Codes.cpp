#include <cstdio>
using namespace std;

int main() {
	int tc,n,k;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&k);
		printf("%d\n", k^(k>>1));
	}

	return 0;
}
