#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v; double dist;
	bool operator <(const Edge &o)const{
		return dist < o.dist;
	}
};

Edge edge[500000];

int p[1001], ecnt;
long long x[1001], y[1001];

int find(int x){
	return x == p[x] ? x : (p[x] = find(p[x]));
}

bool link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return false;
	p[py] = px;
	return true;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		p[i] = i;
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	for(int i = 1; i <= N; i++)
		for(int j = i + 1; j <= N; j++)
			edge[ecnt++] = {i, j, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))};

	int G = N;
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		G -= link(u, v);
	}

	sort(edge, edge + ecnt);

	double ans = 0;
	for(int i = 0; i < ecnt && G > 1; i++)
		if(link(edge[i].u, edge[i].v)){
			ans += edge[i].dist;
			G--;
		}
	printf("%.2lf\n", ans);

	return 0;
}