/*
	2019 Ajou Univ. Programming Contest
	세훈이의 선물가게 - 서브태스크2
	Acka's cpp solution
	Time Complexity: O(sum(M))
*/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node{ int t, cnt; };

queue<Node> bq, rq;
vector<int> b, r;

void assign(queue<Node> &q, vector<int> &ans, int add, int num){
	ans.push_back(num);
	int t = q.front().t + add;
	if(--q.front().cnt == 0) q.pop();
	if(!q.empty()) q.front().t = max(q.front().t, t);
}

int main()
{
	int A, B, N, cur = 1; scanf
	("%d %d %d", &A, &B, &N);
	for(int i = 0, t, m; i < N; i++){
		char c; scanf("%d %c %d", &t, &c, &m);
		if(c == 'B') bq.push({t, m});
		else rq.push({t, m});
	}

	while(!bq.empty() || !rq.empty()){
		if(!bq.empty() && (rq.empty() || bq.front().t <= rq.front().t))
			assign(bq, b, A, cur++);
		else assign(rq, r, B, cur++);
	}

	printf("%d\n", b.size());
	for(int i = 0; i < b.size(); i++)
		printf("%d ", b[i]);
	printf("\n%d\n", r.size());
	for(int i = 0; i < r.size(); i++)
		printf("%d ", r[i]);
	printf("\n");

	return 0;
}
