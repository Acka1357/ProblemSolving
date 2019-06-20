#include <cstdio>

int N, K, s, t, r;

int calc(){
	int cnt = (N + s * t - 1) / (s * t);
	int st = (cnt - 1) * (t + r);
	int rem = N - ((cnt - 1) * s * t);
	int acnt = rem / s;
	return st + acnt + (rem != acnt * s);
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < K; i++){
		scanf("%d %d %d", &s, &t, &r);
		printf("%d\n", calc());
	}
	return 0;
}
