#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int BASE = 100001;
const int CRD_COUNT = BASE * 2 - 1;

int tree[1 << 19][2], NN, l[50001], r[50001], nxt[50001][2];
ll d[50001][2];

int point_max(int qi, int l = 1, int r = NN, int idx = 1){
	if(l == r) return max(tree[idx][0], tree[idx][1]);
	if(tree[idx][1]){
		tree[idx * 2][1] = max(tree[idx * 2][1], tree[idx][1]);
		tree[idx * 2 + 1][1] = max(tree[idx * 2 + 1][1], tree[idx][1]);
		tree[idx][0] = max(tree[idx][0], tree[idx][1]);
		tree[idx][1] = 0;
	}
	return qi <= (l + r) / 2 ? 
			point_max(qi, l, (l + r) / 2, idx * 2) :
			point_max(qi, (l + r) / 2 + 1, r, idx * 2 + 1);
}

void range_update(int ql, int qr, int val, int l = 1, int r = NN, int idx = 1){
	if(qr < l || ql > r) return ;
	if(ql <= l && r <= qr){
		tree[idx][1] = val;
		return ;
	}
	range_update(ql, qr, val, l, (l + r) / 2, idx * 2);
	range_update(ql, qr, val, (l + r) / 2 + 1, r, idx * 2 + 1);
}

int absx(int x){
	return x < 0 ? -x : x;
}

int main()
{
	int N, S; scanf("%d %d", &N, &S);
	for(int i = N; i > 0; i--)
		scanf("%d %d", &l[i], &r[i]);

	for(NN = 1; NN < CRD_COUNT; NN <<= 1);
	for(int i = 1; i <= N; i++){
		l[i] += BASE; r[i] += BASE;
		nxt[i][0] = point_max(l[i]);
		nxt[i][1] = point_max(r[i]);
		range_update(l[i], r[i] - 1, i);
	}

	S += BASE;
	l[0] = r[0] = BASE;

	memset(d, 0x3f,sizeof(d));
	d[N][0] = absx(S - l[N]);
	d[N][1] = absx(S - r[N]);
	
	for(int i = N; i > 0; i--){
		int &nl = nxt[i][0], &nr = nxt[i][1];
		d[nl][0] = min(d[nl][0], d[i][0] + absx(l[nl] - l[i]));
		d[nl][1] = min(d[nl][1], d[i][0] + absx(r[nl] - l[i]));
		d[nr][0] = min(d[nr][0], d[i][1] + absx(l[nr] - r[i]));
		d[nr][1] = min(d[nr][1], d[i][1] + absx(r[nr] - r[i]));
	}
	printf("%lld\n", min(d[0][0], d[0][1]));

	return 0;
}
