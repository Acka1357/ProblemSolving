#include <cstdio>

bool set_root(int rv, int l, int r){
	if(l == r) return true;
	int ll = l, lr = rv - 1, rl = rv + 1, rr = r;
	int lcnt = lr - ll + 1, rcnt = rr - rl + 1;
	bool lpsb = (ll > lr), rpsb = (rl > rr);
	int mid = (ll + lr) / 2;
	if(!lpsb && (rv & 1) != (mid & 1)) 
		lpsb |= set_root(mid, ll, lr);
	if(!lpsb && !(lcnt & 1) && (rv & 1) == (mid & 1))
		lpsb |= set_root(mid + 1, ll, lr);
	if(!lpsb) return false;

	mid = (rl + rr) / 2;
	if(!rpsb && (rv & 1) == (mid & 1))
		rpsb |= set_root(mid, rl, rr);
	if(!rpsb && !(rcnt & 1) && (rv & 1) != (mid & 1))
		rpsb |= set_root(mid + 1, rl, rr);

	return rpsb;
}

int main()
{
	int N; scanf("%d", &N);
	int ans = set_root((N + 1) / 2, 1, N);
	if(!(N & 1)) ans += set_root(N / 2 + 1, 1, N);
	printf("%d\n", ans);
	return 0;
}