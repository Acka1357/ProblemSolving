#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Edge{
	int to; long long cost;
	Edge(int t, long long c):to(t), cost(c){}
};

struct Node{
	int cur, dec;
	long long sum;
	Node(int cur, int dec, long long sum):cur(cur), dec(dec), sum(sum){}
	bool operator <(const Node &o)const{
		return sum == o.sum ? dec > o.dec : sum > o.sum;
	}
};

long long mind[100001][2];
vector adj[100001];

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N, M; scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; i++)
			adj[i].clear();
		for(int i = 0, u, v, c; i < M; i++){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].push_back(Edge(v, c));
			adj[v].push_back(Edge(u, c));
		}

		long long ans = -1;
		memset(mind, 0x3f, sizeof(mind));
		priority_queue<Node> q;
		q.push(Node(1, 0, mind[1][0] = 0));
		while(!q.empty()){
			int cur = q.top().cur, dec = q.top().dec;
			long long sum = q.top().sum; q.pop();
			if(cur == N){
				ans = sum; break;
			}

			for(int i = 0; i < adj[cur].size(); i++){
				int &next = adj[cur][i].to;
				long long &cost = adj[cur][i].cost, nc = sum + cost;
				if(!dec && cost)
			}
		}

		printf("Case #%d\n%d\n", tc, ans);
	}
	return 0;
}