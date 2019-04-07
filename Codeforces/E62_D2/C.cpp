#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

struct Info{
	ll t, b;
	bool operator<(const Info &o)const{
		return t == o.t ? b > o.b : t > o.t;
	}
};

bool cmp(const Info &a, const Info &b){
	return a.b == b.b ? a.t > b.t : a.b > b.b;
}

Info info[300001];

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%lld %lld", &info[i].t, &info[i].b);

	sort(info, info + N, cmp);
	priority_queue<Info> q;
	ll ans = 0, suml = 0;
	for(int i = 0; i < N; i++){
		suml += info[i].t;
		q.push({info[i].t, info[i].b});
		while(q.size() > K){
			suml -= q.top().t;
			q.pop();
		}
		ans = max(ans, suml * info[i].b);
	}

	printf("%lld\n", ans);

	return 0;
}
