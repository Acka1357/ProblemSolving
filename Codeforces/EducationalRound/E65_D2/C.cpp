#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

int par[500001], sz[500001];

int find(int x){
	return (par[x] == x) ? x : (par[x] = find(par[x]));
}

void link(int x, int y){
	int px = find(x), py = find(y);
	if(px != py){
		sz[px] += sz[py];
		par[py] = px;
	}
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		par[i] = i, sz[i] = 1;

	for(int i = 0, n, x, p; i < M; i++){
		scanf("%d", &n);
		if(n) scanf("%d", &p);
		for(int j = 1; j < n; j++){
			scanf("%d", &x);
			link(p, x);
			p = x;
		}
	}

	for(int i = 1; i <= N; i++)
		printf("%d%c", sz[find(i)], " \n"[i == N]);

	return 0;
}
