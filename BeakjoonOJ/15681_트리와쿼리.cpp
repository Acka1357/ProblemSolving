#include <cstdio>
#include <vector>
using namespace std;

int N, R, Q, sub[100001], chk[100001];
vector<int> adj[100001];

int count_sub(int x){
	chk[x] = true;
	for(int &ch : adj[x])
		if(!chk[ch]) sub[x] += count_sub(ch);
	return ++sub[x];
}

int main()
{
	scanf("%d %d %d", &N, &R, &Q);
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	count_sub(R);

	for(int i = 0, q; i < Q; i++){
		scanf("%d", &q);
		printf("%d\n", sub[q]);
	}

	return 0;
}