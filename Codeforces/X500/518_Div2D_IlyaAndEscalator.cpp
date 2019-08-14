#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

int N, T;
ld P, d[2001][2001];

int main()
{
	scanf("%d %Lf %d", &N, &P, &T);
	d[0][0] = 1;
	for(int i = 1; i <= T; i++)
		for(int j = 0; j <= i; j++){
			if(j) d[i][j] += d[i - 1][j - 1] * P;
			d[i][j] += d[i - 1][j] * (1 - P);
		}
	
	ld ans = 0;
	for(int i = 0; i <= T; i++)
		ans += d[T][i] * min(i, N);
	printf("%.9Lf\n", ans);

	return 0;
}