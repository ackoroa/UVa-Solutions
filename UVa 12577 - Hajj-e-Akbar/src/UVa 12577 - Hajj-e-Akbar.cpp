#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int cnt = 1;
	char s[20];

	while(true){
		scanf("%s",s);
		if(strcmp(s,"*")==0) return 0;

		printf("Case %d: ",cnt++);
		if(strcmp(s,"Hajj")==0) printf("Hajj-e-Akbar\n");
		else if(strcmp(s,"Umrah")==0) printf("Hajj-e-Asghar\n");
	}

	return 0;
}
