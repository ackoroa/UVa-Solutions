#include <cstdio>
using namespace std;

int main() {
	char c;
	while(scanf("%c",&c) != EOF){
		if(c!='\n')printf("%c",c-7);
		else printf("\n");
	}

	return 0;
}
