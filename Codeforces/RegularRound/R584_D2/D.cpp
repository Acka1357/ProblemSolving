#include <cstdio>

typedef long long ll;

int par[100005], gsize[100005];

int find(int x){ 
	return x == par[x] ? x : (par[x] = find(par[x])); 
}

bool link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return false;
	par[py] = px;
	gsize[px] += gsize[py];
	return true;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		par[i] = i, gsize[i] = 1;
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		link(u, v);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++)
		if(par[i] == i) ans += gsize[i] - 1;
	printf("%d\n", max(0, M - ans));

	return 0;
}
