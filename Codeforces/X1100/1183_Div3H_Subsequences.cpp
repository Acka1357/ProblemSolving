#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

char s[105];
int L, chk[256];
ll K, d[105][105], cand[105];

int main()
{
	scanf("%d %lld %s", &L, &K, s + 1);

	d[0][0] = 1;
	for(int i = 0, cchk = 1; i <= L; i++)
		for(int len = 0; len <= i; len++, cchk++){
			if(d[i][len] > K) d[i][len] = -1;
			if(cand[len] < 0 || d[i][len] < 0) cand[len] = -1;
			else cand[len] += d[i][len];
			
			for(int j = i + 1; j <= L; j++)
				if(chk[s[j]] != cchk){
					chk[s[j]] = cchk;
					if(d[i][len] < 0 || d[j][len + 1] < 0) d[j][len + 1] = -1;
					else d[j][len + 1] += d[i][len];
				}
		}

	ll ans = 0, sum = 0;
	for(int i = L; i >= 0; i--){
		ll cnt = min(K - sum, cand[i] < 0 ? K : cand[i]);
		ans += cnt * (L - i);
		sum += cnt;
	}
	printf("%lld\n", sum == K ? ans : -1);

	return 0;
}