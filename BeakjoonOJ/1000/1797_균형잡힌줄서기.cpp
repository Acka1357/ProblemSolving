#include <cstdio>
#include <algorithm>
using namespace std;

struct P{
	int x, s;
	bool operator <(const P &o)const{
		return x < o.x;
	}
};

int N, lx[2000001];
P p[1000001];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &p[i].s, &p[i].x);

	sort(p + 1, p + N + 1);

	int cur = N, ans = 0;
	for(int i = 1; i <= N; i++){
		if(!lx[cur]) lx[cur] = p[i].x;
		cur += (p[i].s ? 1 : -1);
		if(lx[cur]) ans = max(ans, p[i].x - lx[cur]);
	}

	printf("%d\n", ans);

	return 0;
}
