#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

char names[10][110];
priority_queue<pair<int, int> > pq;

int main() {
	int tc,p,count=1;
	scanf("%d",&tc);

	while(tc--){
		printf("Case #%d:\n",count++);
		for(int i=0;i<10;i++){
			scanf("%s %d",names[i],&p);
			pq.push(pair<int,int>(p,-i));
		}

		p = pq.top().first;
		while(pq.top().first == p){
			printf("%s\n",names[-pq.top().second]);
			pq.pop();
		}
		while(!pq.empty()) pq.pop();
	}

	return 0;
}
