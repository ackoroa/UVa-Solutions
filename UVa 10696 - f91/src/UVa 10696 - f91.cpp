#include <cstdio>
using namespace std;

int f91(int n) {
	if (n >= 101)
		return n - 10;
	if (n <= 100)
		return f91(f91(n + 11));
}

int main() {
	int n;

//	for(int i=1;i<=100;i++){
//		printf("%d ",f91(i));
//	}
//	return 0;

	while (scanf("%d", &n), n) {
		printf("f91(%d) = ", n);
		if (n >= 101)
			printf("%d\n", n - 10);
		else
			printf("91\n");
	}

	return 0;
}
