#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

struct Node{
	long long sum;
	int i1, i2;
	Node(int i1, int i2, long long s):i1(i1), i2(i2), sum(s){}
	bool operator <(const Node &o)const{
		return sum > o.sum;
	}
};

long long absx(long long x){
	return x < 0 ? -x : x;
}

int p[500000];
long long a[500000];

int find(int x){
	return p[x] == x ? x : (p[x] = find(p[x]));	
}

void link(int x, int y){
	p[find(y)] = find(x);
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &a[i]);

	priority_queue<Node> q;
	for(int i = 0; i < N; i++){
		p[i] = i;
		q.push(Node(i, i, a[i]));
	}

	// for(int i = 1; i < N; i++)
	// 	if(i - 1 != maxi && i != maxi)
	// 		q.push(Node(i - 1, i, -absx(a[i] - a[i - 1])));

	int rem = N - 2;
	while(rem){
		int i1 = q.top().i1, i2 = q.top().i2;
		long long sum = q.top().sum; q.pop();
		if(p[i1] != i1 || p[i2] != i2) continue;
		rem--;
		printf("%d %d %lld\n", i1, i2, sum); 
		link(i1, i2);
		if(i1) q.push(Node(find(i1 - 1), i1, -absx(sum - a[find(i1 - 1)])));
		if(i2 < N - 1) q.push(Node(i1, find(i2 + 1), -absx(sum - a[find(i2 + 1)])));
	}

	long long v1, v2;
	while(!q.empty()){
		int i1 = q.top().i1, i2 = q.top().i2;
		long long sum = q.top().sum; q.pop();
		if(p[i1] != i1 || p[i2] != i2) continue;
		else{
			printf("%d %d %lld\n", i1, i2, sum);
			v1 = sum;
			break;
		}
	}
	while(!q.empty()){
		int i1 = q.top().i1, i2 = q.top().i2;
		long long sum = q.top().sum; q.pop();
		if(p[i1] != i1 || p[i2] != i2) continue;
		else{
			printf("%d %d %lld\n", i1, i2, sum);
			v2 = sum;
			break;
		}
	}

	printf("%lld\n", absx(v1 - v2));
	return 0;
}
