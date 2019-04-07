#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node{
	int frq;
	Node* next[26], maxf[5];
};

struct Range{
	int l, r;
	bool operator <(const Range &o)const{
		return l == o.l ? r > o.r : l < o.l;
	}
};

Range range[25001];
int N, T, tree[1 << 21], NN;
vector<int> rs;

void change_min(int ql, int qr, int val, int l = 0, int r = NN - 1, int idx = 1){
	if(ql <= l && r <= qr) tree[idx] = min(tree[idx], val);
	else if(r < ql || qr < l) return ;
	else{
		change_min(ql, qr, val, l, (l + r) / 2, idx * 2);
		change_min(ql, qr, val, (l + r) / 2 + 1, r, idx * 2 + 1);
	}
}

int get_min(int idx){
	int ret = tree[NN + idx];
	for(int i = NN + idx; i > 0; i >>= 1)
		ret = min(ret, tree[i]);
	return ret;
}

int main()
{
	memset(tree, 0x3f, sizeof(tree));

	scanf("%d %d", &N, &T);
	for(int i = 0, l, r; i < N; i++)
		scanf("%d %d", &range[i].l, &range[i].r);

	sort(range, range + N);
	for(NN = 1; NN <= T; NN <<= 1);

	change_min(0, 0, 0);
	for(int i = 0; i < N; i++){
		int v = get_min(range[i].l - 1);
		if(v == INF) return !printf("-1\n");
		change_min(range[i].l, range[i].r, v + 1);
	}

	int ans = get_min(T);
	printf("%d\n", ans == INF ? -1 : ans);

	return 0;
}


// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <tuple>
// using namespace std;

// struct se{
// 	int s, e;
// 	bool operator<(const se &o) const{
// 		return tie(s,o.e)<tie(o.s,e);
// 	}
// } inp[30004];
// int ans;
// int main(){
// 	int base=0;
// 	int N,T; scanf("%d %d",&N,&T);
// 	for(int i=1;i<=N;i++){
// 		int s,e; scanf("%d %d",&s,&e);
// 		inp[i]={s,e};
// 	}
// 	int i=1;
// 	sort(inp+1,inp+N+1);
// 	for(int t=1;t<=T;t++){
// 		if(base<t){
// 			int ret=base;
// 			while(i<=N && inp[i].s<=t){
// 				ret=max(ret,inp[i++].e);
// 			}
// 			ans++;
// 			base=ret;
// 		}
// 		if(base<t) return !printf("-1");
// 	}
// 	printf("%d",ans);
// }