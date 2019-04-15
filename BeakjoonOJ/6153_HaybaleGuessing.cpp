// solution:
// 각 세그먼트와 밸류를 압축한 뒤, 어떤 쿼리 pi까지 모두 처리했을때 가능한지를 바이너리 서치.
// 가능함의 판단은 높은 밸류부터 시작해 해당 밸류의 영역을 모두 1로 마킹하고, 
// 이번 쿼리를 처리할 때 해당 [l, r] 구간에 비어있는 칸이 하나라도 있으면 가능.
// pi이전의 쿼리 증 비어있는 칸이 하나도 없는 쿼리가 있다면 불가능.
// * 모든 인덱스의 값이 유니크하다. 따라서 같은 밸류를 묶어 공통 쿼리 범위를 뽑아내야 한다.
// * 밸류 압축 시, 구간 업데이트를 통해 non-zero counting tree를 사용함으로 그 밸류만이 아니라 패딩용 값이 추가로 필요하다.
//  [2,4], [7,9]가 있을때 이 구간이 [1,2], [3,4]로 압축되면 사이에 [5,6]의 빈 공간이 있음에도
//  두 구간이 붙어있어 공간이 없는 것으로 처리된다. 생각하기 귀찮으니 l-1, r+1 밸류를 같이 압축했음.

// 시간복잡도: O(Q * (logQ)^2)
// 분류: Segment Tree, Binary Search
// 난이도: 2000 - 2250

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

struct Seg{ int l, r, idx; };
struct Node{ int fill, cnt; };

Node tree[1 << 18];
vector<Seg> seg[25001];
int N, Q, NN, V, org_l[25000], org_r[25000], org_v[25000];

void fill_range(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(qr < l || r < ql) return ;
	if(ql <= l && r <= qr){
		tree[idx].fill = tree[idx].cnt = r - l + 1;
		return ;
	}
	fill_range(ql, qr, l, (l + r) / 2, idx * 2);
	fill_range(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1);
	tree[idx].cnt = max(tree[idx].cnt, tree[idx * 2].cnt + tree[idx * 2 + 1].cnt);
}

int range_count(int ql, int qr, int l = 1, int r = NN, int idx = 1){
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return tree[idx].cnt;
	if(tree[idx].fill) return min(qr, r) - max(ql, l) + 1;
	return range_count(ql, qr, l, (l + r) / 2, idx * 2)
		   + range_count(ql, qr, (l + r) / 2 + 1, r, idx * 2 + 1);
}

bool valid(int pi){
	memset(tree, 0, sizeof(tree));
	for(int v = V; v > 0; v--){
		int l = 0, r = N + 1;
		for(Seg &s : seg[v])
			if(s.idx <= pi){
				l = max(l, s.l), r = min(r, s.r);
			}
		if(l == 0 || r == N + 1) continue;
		if(l > r || range_count(l, r) == r - l + 1)
			return false;

		for(Seg &s : seg[v])
			if(s.idx <= pi)
				fill_range(s.l, s.r);
	}
	return true;
}

int main()
{
	scanf("%d %d", &N, &Q);
	vector<int> xs(Q * 4), vs(Q);
	for(int i = 0, xi = 0; i < Q; i++){
		scanf("%d %d %d", &org_l[i], &org_r[i], &org_v[i]);
		xs[xi++] = org_l[i]; xs[xi++] = org_r[i];
		xs[xi++] = org_l[i] - 1; xs[xi++] = org_r[i] + 1;
		vs[i] = org_v[i];
	}

	sort(xs.begin(), xs.end()); 
	sort(vs.begin(), vs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	vs.erase(unique(vs.begin(), vs.end()), vs.end());

	N = xs.size(); V = vs.size();
	map<int, int> xmap, vmap;
	for(int i = 0; i < N; i++)
		xmap[xs[i]] = i + 1;
	for(int i = 0; i < V; i++)
		vmap[vs[i]] = i + 1;

	for(NN = 1; NN < N; NN <<= 1);
	for(int i = 0; i < Q; i++)
		seg[vmap[org_v[i]]].push_back({xmap[org_l[i]], xmap[org_r[i]], i + 1});

	int l = 1, r = Q, m, ans = 0;
	while(l <= r){
		m = (l + r) / 2;
		if(valid(m)) l = m + 1;
		else r = m - 1, ans = m;
	}
	printf("%d\n", ans);

	return 0;
}