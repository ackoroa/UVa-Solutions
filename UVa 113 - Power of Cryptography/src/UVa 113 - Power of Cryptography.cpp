#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double base, num;

	while(scanf("%lf\n%lf",&base,&num)!=EOF){
		printf("%.0lf\n",pow(num,1.0/base));
	}

	return 0;
}
