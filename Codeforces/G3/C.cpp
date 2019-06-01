#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int N, M, a[300001], p[300001], o[300001];
vector<pair<int,int>> ans;

int pswap(int ai, int bi){
	ans.push_back({p[ai], p[bi]});
	swap(p[ai], p[bi]);
	swap(a[p[ai]], a[p[bi]]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}

	M = N / 2;

	for(int i = 2; i < N; i++){
		if(p[i] == i) continue;
		if(p[i] <= M) pswap(i, a[N]);
		else pswap(i, a[1]);
		if(p[i] <= M && i <= M) pswap(i, a[N]);
		else if(p[i] >= M && i >= M) pswap(i,  a[1]);
		pswap(i, a[i]);
	}

	if(p[1] != 1 && p[1] <= M) pswap(1, a[N]);
	if(p[1] != 1) pswap(a[1], 1);
	if(p[N] != N && p[N] > M) pswap(a[1], N);
	if(p[N] != N) pswap(a[N], N);

	printf("%d\n", ans.size());
	for(auto &pii : ans)
		printf("%d %d\n", pii.first, pii.second);

	return 0;
}
