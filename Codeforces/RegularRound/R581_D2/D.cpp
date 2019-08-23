#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int lidx[100005], ridx[100005], par[100005];
char s[100005], ans[100005];

int find(int x){
	return par[x] == x ? x : (par[x] = find(par[x]));
}

void link(int x, int y){
	int px = find(x), py = find(y);
	if(px == py) return ;
	par[py] = px;
	lidx[px] = min(lidx[px], lidx[py]);
	ridx[px] = max(ridx[px], ridx[py]);
	ans[lidx[px]] = s[lidx[px]];
	ans[ridx[px]] = s[ridx[px]];
}

int main()
{
	scanf("%s", s);

	queue<int> q;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		par[i] = lidx[i] = ridx[i] = i;

	for(int i = 1; i < len; i++)
		if(s[i - 1] == '1' && s[i] == '0'){
			link(i, i - 1);
			q.push(i);
		}

	while(!q.empty()){
		int px = find(q.front()); q.pop();
		int nl = lidx[px] - 1, nr = ridx[px] + 1;
		while(nl >= 0){
			int py = find(nl);
			if(lidx[py] == ridx[py]) break;
			link(px, py);
			nl = lidx[py] - 1;
		}
		while(nr < len){
			int py = find(nr);
			if(lidx[py] == ridx[py]) break;
			link(px, py);
			nr = ridx[py] + 1;
		}
		if(nl >= 0 && nr < len && s[nl] == '1' && s[nr] == '0'){
			q.push(px);
			link(px, nl); link(px, nr);
		}
	}

	for(int i = 0; i < len; i++)
		printf("%c", ans[i] ? ans[i] : '0');
	printf("\n");

	return 0;
}