#include <cstdio>
using namespace std;

int main() {
	int tc,n,t[50];

	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
				scanf("%d",&t[i]);
		}

		int ans = 0;
		bool sw;
		for(int i=0;i<n;i++){
			sw = false;
			for(int j=1;j<n-i;j++){
				if(t[j]<t[j-1]){
					int temp = t[j];
					t[j] = t[j-1];
					t[j-1] = temp;
					ans++;
					sw = true;
				}
			}
			if(!sw) break;
		}
		printf("Optimal train swapping takes %d swaps.\n",ans);
	}

	return 0;
}
