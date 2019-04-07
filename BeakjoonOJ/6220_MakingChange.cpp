#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, C, d[1001], w[11];

int main()
{
	scanf("%d %d", &C, &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &w[i]);

	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j <= C; j++)
			if(j >= w[i]) d[j] = min(d[j], d[j - w[i]] + 1);
	printf("%d\n", d[C]);

	return 0;
}
