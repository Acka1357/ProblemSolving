#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Store{
	int i, p;
	bool operator <(const Store &o)const{
		return p < o.p;
	}
};

Store st[401];
int N, p[401], w[401][401], d[401];

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
		st[i].i = i; st[i].p = p[i];
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			scanf("%d", &w[i][j]);
	for(int i = 1; i <= N; i++)
		w[0][i] = w[1][i], w[i][0] = 0x3f3f3f3f;

	sort(st + 1, st + N + 1);
	memset(d, 0xff, sizeof(d));
	d[0] = 0;
	for(int i = 1; i <= N; i++){
		int to = st[i].i, when = st[i].p;
		for(int from = 0; from <= N; from++)
			if(from != to && d[from] >= 0 && p[from] + w[from][to] <= when)
				d[to] = max(d[to], d[from] + 1);
	}

	int ans = -1;
	for(int i = 0; i <= N; i++)
		ans = max(ans, d[i]);
	printf("%d\n", ans);

	return 0;
}
