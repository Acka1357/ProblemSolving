#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v, c;
	bool operator <(const Edge &o)const{
		return c > o.c;
	}
};

int p[1001];

int find(int x){
	return p[x] == x ? p[x] : (p[x] = find(p[x]));
}

void link(int px, int py){
	p[py] = px;
}

Edge edge[20000];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++)
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].c);
	for(int i = 1; i <= N; i++) p[i] = i;

	sort(edge, edge + M);

	int ans = 0, cnt = 0, px, py;
	for(int i = 0; i < M; i++){
		px = find(edge[i].u);
		py = find(edge[i].v);
		if(px == py) continue;
		link(px, py);
		ans += edge[i].c;
		cnt++;
	}
	printf("%d\n", cnt == N - 1 ? ans : -1);

	return 0;
}