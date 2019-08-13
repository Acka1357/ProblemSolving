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

const ll MOD = 1000000007;

ll N, M, pmat[70][101][101], org[101], fin[101][101];

void mat_mult(ll ma[][101], ll mb[][101], ll res[][101]){
	ll save[101][101] = { 0, };
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < M; k++)
				save[i][j] = (save[i][j] + ma[i][k] * mb[k][j]) % MOD;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			res[i][j] = save[i][j] % MOD;
}

int main()
{
	scanf("%lld %lld", &N, &M);
	
	for(int i = 0; i < M; i++)
		org[i] = fin[i][i] = 1;
	for(int i = 0; i < M - 1; i++)
		pmat[0][i][i + 1] = 1;
	pmat[0][M - 1][0] = pmat[0][M - 1][M - 1] = 1;

	if(N < M) return 0 & printf("1\n");

	N -= M - 1;
	for(ll i = 0; N; i++, N >>= 1){
		if(N & 1) mat_mult(fin, pmat[i], fin);
		mat_mult(pmat[i], pmat[i], pmat[i + 1]);
	}
	
	ll ans = 0;
	for(int i = 0; i < M; i++)
		ans = (ans + fin[M - 1][i]) % MOD;
	printf("%lld\n", ans);

	return 0;
}
