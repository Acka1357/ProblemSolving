#include <cstdio>
#include <algorithm>
using namespace std;

struct Info{
	long long idx, x, y, d;
	bool operator <(const Info &o){
		return d == o.d ? idx < o.idx : d < o.d;
	}
};

long long ans[300002], x[300002], y[300002];
long long cumlx[300002], cumry[300002];
Info info[300002];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++){
		scanf("%lld %lld", &x[i], &y[i]);
		info[i].x = x[i]; info[i].y = y[i];
		info[i].d = x[i] - y[i]; info[i].idx = i;
	}
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		if(x[u] + y[v] < x[v] + y[u]){
			ans[u] -= (x[u] + y[v]);
			ans[v] -= (x[u] + y[v]);
		}
		else{
			ans[u] -= (x[v] + y[u]);
			ans[v] -= (x[v] + y[u]);
		}
	}

	sort(info + 1, info + N + 1);

	for(int i = 1; i <= N; i++)
		cumlx[i] = cumlx[i - 1] + info[i].x;
	for(int i = N; i >= 1; i--)
		cumry[i] = cumry[i + 1] + info[i].y;

	for(int i = 1; i <= N; i++)
		ans[info[i].idx] += (N - i) * info[i].x + (i - 1) * info[i].y + cumlx[i - 1] + cumry[i + 1];

	for(int i = 1; i <= N; i++)
		printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}