#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Rail{
	int l, r, f, c;
	bool operator <(const Rail &o)const{
		return l < o.l; 
	}
};

Rail rail[10000];
int d[1001][1001];

int main()
{
	int L, N, B; scanf("%d %d %d", &L, &N, &B);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d", &rail[i].l, &rail[i].r, &rail[i].f, &rail[i].c);
		rail[i].r += rail[i].l;
	}

	sort(rail, rail + N);
	memset(d, 0xff, sizeof d);

	d[0][0] = 0;
	for(int i = 0; i < N; i++)
		for(int j = rail[i].c; j <= B; j++){
			if(rail[i].l && d[rail[i].l][j - rail[i].c] < 0) continue;
			d[rail[i].r][j] = max(d[rail[i].r][j], d[rail[i].l][j - rail[i].c] + rail[i].f);
		}

	int ans = -1;
	for(int i = 0; i <= B; i++)
		ans = max(ans, d[L][i]);
	printf("%d\n", ans);

	return 0;
}
