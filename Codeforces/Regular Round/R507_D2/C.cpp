#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

struct Node{
	long long dead, mint;
	Node(long long d, long long t): dead(d), mint(t){}
	bool operator <(const Node &o)const{
		return dead == o.dead ? mint > o.mint : dead > o.dead;
	}
};

long long a[200000], x[200000], ans[200000];

int main()
{
	long long N, T; scanf("%lld %lld", &N, &T);
	for(int i = 0; i < N; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < N; i++)
		scanf("%lld", &x[i]);

	priority_queue<Node> q;
	for(int i = 0; i < N; i++)
		q.push(Node(x[i] - 1, a[i] + T));

	long long t = 0;
	for(int i = 0; i < N; i++){
		long long dead = q.top().dead, mint = q.top().mint; q.pop();
		printf("%lld %lld\n", dead, mint);
		if(dead < i) return !printf("No\n");
		ans[i] = t = max(t, mint);
	}

	printf("YES\n");
	for(int i = 0; i < N; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}
