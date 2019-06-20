#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int N, x; scanf("%d", &N);
	queue<int> q;
	while(scanf("%d", &x)){
		if(x < 0) break;
		if(x == 0) q.pop();
		else if(q.size() < N) q.push(x);
	}
	if(q.empty()) printf("empty\n");
	for(; !q.empty(); q.pop())
		printf("%d%c", q.front(), " \n"[q.size() == 1]);

	return 0;
}