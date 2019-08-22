#include <cstdio>

typedef long long ll;

ll cur[500005], sum[800][800];

int main()
{
	int Q; scanf("%d", &Q);
	while(Q--){
		ll cmd, x, y; scanf("%lld %lld %lld", &cmd, &x, &y);
		// printf("%lld %lld %lld\n", cmd, x, y);
		if(cmd == 1){
			ll past = cur[x];
			cur[x] += y;
			ll add = cur[x] - past;
			for(int i = 1; i <= 708; i++)
				sum[i][x % i] += add;
		}
		else if(x < 708){
			printf("%lld\n", sum[x][y]);
		}
		else{
			ll ans = 0;
			for(int i = 0; i <= 500000; i += x)
				if(i + y <= 500000) ans += cur[i + y];
			printf("%lld\n", ans);
		}
	}
	return 0;
}