#include <cstdio>
using namespace std;

int main() {
	// v = u + at
	// d = ut + .5 a t^2

	int v1, t1;
	while(scanf("%d %d", &v1, &t1) != EOF){
		printf("%d\n",2*v1*t1);
	}

	return 0;
}
