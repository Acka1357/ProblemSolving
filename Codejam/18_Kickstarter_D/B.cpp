#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Crd{
	int x, y;
	Crd(){} Crd(int x, int y):x(x), y(y){}
	bool operator <(const Crd &o)const{
		return x == o.x ? y < o.y : x < o.x;
	}
};

long long p[1001], h[1001], x[1001], y[1001];
Crd ts[1001], bs[1001];

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N, K; scanf("%d %d", &N, &K);

		long long A1, B1, C1, M1, A2, B2, C2, M2, A3, B3, C3, M3, A4, B4, C4, M4;
		scanf("%lld %lld %lld %lld %lld %lld", &p[1], &p[2], &A1, &B1, &C1, &M1);
		scanf("%lld %lld %lld %lld %lld %lld", &h[1], &h[2], &A2, &B2, &C2, &M2);
		scanf("%lld %lld %lld %lld %lld %lld", &x[1], &x[2], &A3, &B3, &C3, &M3);
		scanf("%lld %lld %lld %lld %lld %lld", &y[1], &y[2], &A4, &B4, &C4, &M4);
		
		for(int i = 3; i <= N; i++){
			p[i] = (A1 * p[i - 1] + B1 * p[i - 2] + C1) % M1 + 1;
			h[i] = (A2 * p[i - 1] + B2 * p[i - 2] + C2) % M2 + 1;
		}
		for(int i = 3; i <= K; i++){
			x[i] = (A3 * p[i - 1] + B3 * p[i - 2] + C3) % M3 + 1;
			y[i] = (A4 * p[i - 1] + B4 * p[i - 2] + C4) % M4 + 1;
		}

		for(int i = 1; i <= N; i++)
			ts[i] = Crd(p[i], h[i]);
		for(int i = 1; i <= K; i++)
			bs[i] = Crd(x[i], y[i]);

		sort(ts + 1, ts + N + 1);
		sort(bs + 1, bs + K + 1);

		bool chk[1001] = {false,};

		int minh = 0x3f3f3f3f;
		for(int i = 1; i <= N; i++){
			minh = min(minh, -ts[i].y - ts[i].x);
			for(int j = 1; j <= K; j++){
				if(bs[j].x < ts[i].x) continue;
				if(-bs[j].y - bs[j].x >= minh) chk[j] = true;
			}
		}

		int maxh = -0x3f3f3f3f;
		for(int i = N; i > 0; i--){
			maxh = max(maxh, ts[i].y - ts[i].x);
			for(int j = K; j > 0; j--){
				if(bs[j].x > ts[i].x) continue;
				if(bs[j].y - bs[j].x <= maxh) chk[j] = true;
			}
		}

		int ans = 0;
		for(int i = 1; i <= N; i++)
			ans += chk[i];
		
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
