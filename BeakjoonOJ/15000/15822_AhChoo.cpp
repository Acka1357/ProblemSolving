#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int a[2001], b[2001];
ll d[2001][2001];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++)
		scanf("%d", &b[i]);

	memset(d, 0x3f, sizeof(d));

	d[0][0] = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			d[i][j] = min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]})
					  + (a[i] - b[j]) * (a[i] - b[j]);
	printf("%lld\n", d[N][N]);

	return 0;
}