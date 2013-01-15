#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;

	while (scanf("%d",&n),n) {
		vector<int> arr;

		for(int i=0;i<n;i++){
			int m;
			scanf("%d",&m);
			if(m>0) arr.push_back(m);
		}

		int size = arr.size();
		if(size==0) printf("0\n");
		else{
			for(int i=0;i<size;i++){
				printf("%d",arr.at(i));
				if(i!=size-1) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
