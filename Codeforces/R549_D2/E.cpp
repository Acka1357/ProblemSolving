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

const int INF = 0x3f3f3f3f;

vector<int> nidx[200001];
int N, M, Q, p[200001], a[200001], tree[1 << 19], NN, nxt[200001][19], pidx[200001];
char ans[200001];

int range_min(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(ql <= l && r <= qr) return tree[idx];
	if(r < ql || qr < l) return INF;
	return min(range_min(ql, qr, l, (l + r) / 2, idx * 2),
			   range_min(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1));
}

int find_idx(int S, vector<int> &is){
	int l = 0, r = is.size() - 1, m, ret = -1;
	while(l <= r){
		m = (l + r) / 2;
		if(is[m] <= S) l = m + 1;
		else ret = is[m], r = m - 1;
	}
	return ret;
}

bool psb(int l, int r){
	if(r - l + 1 < N) return false;
	return range_min(l, r) <= r;
}

int main()
{
	scanf("%d %d %d", &N, &M, &Q);
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
		pidx[p[i]] = i;
	}
	for(int i = 1; i <= M; i++){
		scanf("%d", &a[i]);
		nidx[a[i]].push_back(i);
	}

	memset(tree, 0x3f, sizeof(tree));
	memset(nxt, 0xff, sizeof(nxt));
	for(NN = 1; NN < M; NN <<= 1);
	for(int i = 1; i <= M; i++)
		nxt[i][0] = find_idx(i, nidx[p[(pidx[a[i]] % N) + 1]]);
	for(int i = 1; i < 19; i++)
		for(int j = 1; j <= M; j++){
			if(nxt[j][i - 1] < 0) continue;
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
		}

	for(int i = 1; i <= M; i++){
		int cur = i, copy = N - 1;
		for(int j = 0; copy && cur > 0; j++, copy >>= 1)
			if(copy & 1) cur = nxt[cur][j];
		if(cur < 0) continue;
		tree[NN + i - 1] = cur;
	}

	for(int i = NN - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

	for(int i = 0, l, r; i < Q; i++){
		scanf("%d %d", &l, &r);
		ans[i] = '0' + psb(l, r);
	}
	printf("%s\n", ans);

	return 0;
}
