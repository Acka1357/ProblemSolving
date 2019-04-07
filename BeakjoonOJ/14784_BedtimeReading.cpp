#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 2000000
#define PCNT 148933

typedef long long ll;

bool np[MAXN + 1], cy[MAXN + 1];
int p[PCNT + 1], bf[MAXN + 1], pcnt, b[MAXN + 1], chk[MAXN + 1], ts, cmin[MAXN + 1];
vector<int> ss;

void set_prime(){
	np[0] = np[1] = true;
	for(ll i = 2; i <= MAXN; i++){
		if(np[i]) continue;
		p[pcnt++] = i; bf[i] = i;
		for(ll j = i * i; j <= MAXN; j += i)
			np[j] = true, bf[j] = i;
	}
}

int calc_bess(int x){
	ll sum = 1, cur = x;
	while(cur > 1){
		int p = bf[cur];
		ll pm = p, m = 0;
		while(cur % p == 0){
			pm *= p; m++;
			cur /= p;
		}
		sum *= (pm - 1) / (p - 1);
	}
	return sum - x;
}

int dfs(int cur){
	int bess = b[cur];
	chk[cur] = ts;
	if(chk[bess] == ts){
		if(bess == cur){
			ss.push_back(cur);
			return 0;
		}
		cmin[bess] = cur;
		return bess;
	}
	if(chk[bess] || !bess) return 0;
	int ci = dfs(b[cur]);
	cmin[ci] = min(cmin[ci], cur);
	if(ci == cur){
		ss.push_back(cmin[ci]);
		return 0;
	}
	return ci;
}

int main()
{
	set_prime();

	int S, E; scanf("%d %d", &S, &E);
	for(int i = S; i <= MAXN; i++){
		int bess = calc_bess(i);
		if(bess >= S && bess <= MAXN)
			b[i] = bess;
	}

	for(int i = S; i <= E; i++)
		if(!chk[i]){
			ts++; dfs(i);
		}

	sort(ss.begin(), ss.end());

	for(int i = 0; i < ss.size(); i++){
		if(ss[i] > E) break;
		printf("%d ", ss[i]);
		for(int cur = b[ss[i]]; cur != ss[i]; cur = b[cur])
			printf("%d ", cur);
		printf("\n");
	}

	return 0;
}