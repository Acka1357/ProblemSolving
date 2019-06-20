#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long N, P;
double up, cum[3000001];

double prob(long long k){
	return up + log10(P) * log10(k) - cum[N + k] + cum[N + k - P];
}

int main()
{
	scanf("%lld %lld", &N, &P);
	for(int i = 1; i < P; i ++)
		up += log10(N - i - 1);
	for(int i = 1; i <= 3000000; i++) 
		cum[i] = cum[i - 1] + log10(i);

	long long lb = 1, rb = 2000000, ans;
	while(lb < rb - 2){
		long long l = lb + (rb - lb) / 3;
		long long r = lb + (2 * (rb - lb)) / 3;
		if(prob(l) < prob(r)) {
			lb = l;
			ans = l;
		}
		else rb = r;
	}
	printf("%.10lf\n", pow(10, max(prob(ans), max(prob(ans + 1), prob(ans + 2)))));
	return 0;
}