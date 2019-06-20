#include <stdio.h>
#include <algorithm>
using namespace std;

#define dist(i1, i2)	absx(x[i1] - x[i2]) + absx(y[i1] - y[i2])
#define absx(x)			((x) < 0 ? (-(x)) : (x))

int d[100001][2], x[100001], y[100001];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d %d", &x[i], &y[i]);

	d[0][0] = 0x3f3f3f3f;
	for(int i = 2; i <= N; i++){
		d[i][0] = d[i - 1][0] + dist(i - 1, i);
		d[i][1] = d[i - 1][1] + dist(i - 1, i);
		if(i != N) d[i][1] = min(d[i][1] , d[i - 2][0] + dist(i - 2, i));
	}
	
	printf("%d\n", min(d[N][0], d[N][1]));
	return 0;
}