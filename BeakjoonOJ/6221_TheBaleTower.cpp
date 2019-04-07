#include <cstdio>
#include <algorithm>
using namespace std;

struct Info{
	int w, h;
	bool operator <(const Info &o)const{
		return w == o.w ? h < o.h : w < o.w;
	}
};

int N, ans;
Info a[20];

void dfs(int idx, int w, int h, int cnt){
	if(idx == N){
		ans = max(ans, cnt);
		return ;
	}
	if(a[idx].w > w && a[idx].h > h)
		dfs(idx + 1, a[idx].w, a[idx].h, cnt + 1);
	dfs(idx + 1, w, h, cnt);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &a[i].w, &a[i].h);

	sort(a, a + N);

	dfs(0, 0, 0, 0);
	printf("%d\n", ans);

	return 0;
}