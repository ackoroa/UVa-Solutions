#include <cstdio>
using namespace std;

int main() {
	int tc, hj, j,n,cur, prev, count=1;

	scanf("%d",&tc);

	while(tc--){
		scanf("%d\n%d",&n,&prev);

		hj=j=0;
		for(int i=0;i<n-1;i++){
			scanf("%d",&cur);
			if(cur>prev)hj++;
			if(cur<prev)j++;
			prev = cur;
		}

		printf("Case %d: %d %d\n",count++,hj,j);
	}

	return 0;
}
