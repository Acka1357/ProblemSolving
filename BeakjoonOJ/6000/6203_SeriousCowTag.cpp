#include <cstdio>

int N, x[1000], y[1000], q[2000], f, r;
bool chk[1000];

int dist(int u, int v){
	return (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &x[i], &y[i]);
		q[r++] = i;
	}

	while(r - f > 1){
		int cur = q[f++], t = -1, mind = 0x3f3f3f3f;
		if(chk[cur]) continue;
		for(int i = 0; i < N; i++)
			if(!chk[i] && i != cur){
				int d = dist(cur, i);
				if(d < mind){
					mind = d;
					t = i;
				}
			}
		chk[t] = true;
		q[r++] = cur;
	}
	printf("%d\n", q[f] + 1);

	return 0;
}
