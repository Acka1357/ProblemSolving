#include <cstdio>
#include <queue>
using namespace std;

int N, K, M, mind[101001];
vector<int> adj[101001];

int main()
{
	scanf("%d %d %d", &N, &K, &M);
	for(int i = 1, v; i <= M; i++)
		for(int j = 0; j < K; j++){
			scanf("%d", &v);
			adj[v].push_back(N + i);
			adj[N + i].push_back(v);
		}

	queue<int> q;
	q.push(mind[1] = 1);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		if(cur == N) return !printf("%d\n", (mind[cur] + 1) / 2);
		for(int &nxt : adj[cur])
			if(!mind[nxt]){
				mind[nxt] = mind[cur] + 1;
				q.push(nxt);
			}
	}
	printf("-1\n");

	return 0;
}