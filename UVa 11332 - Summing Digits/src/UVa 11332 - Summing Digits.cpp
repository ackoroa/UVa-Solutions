#include <cstdio>
using namespace std;

int main() {
	char c=' ';
	int n;

	while(true){
		n = 0;
		while(true){
			scanf("%c",&c);
			if(c=='\n') break;
			n += c - '0';
		}
		if(n==0) return 0;
		while(n>9) n = (n%10) + (n/10);
		printf("%d\n",n);
	}
}
