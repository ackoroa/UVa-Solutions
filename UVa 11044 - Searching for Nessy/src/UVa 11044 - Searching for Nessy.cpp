#include <cstdio>
using namespace std;

int main() {
	int tc, w,h;

	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&w,&h);
		printf("%d\n",(w/3)*(h/3));
	}

	return 0;
}
