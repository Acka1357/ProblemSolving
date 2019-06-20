#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[3001], d[3002][3002][2];

int main()
{
	int N, B; scanf("%d %d", &N, &B);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	memset(d, 0xff, sizeof(d));
	d[0][0][0] = 0;
	for(int i = 1; i <= N; i++){
		d[i][0][0] = d[i - 1][0][0];
		for(int j = min(i, B); j > 0; j--){
			if(d[i - 1][j - 1][1] >= 0)
				d[i][j][1] = d[i - 1][j - 1][1] + a[i];
			d[i][j][1] = max(d[i][j][1], d[i - 1][j - 1][0]);
			d[i][j][0] = max(d[i - 1][j][0], d[i - 1][j][1]);
		}
	}
	printf("%d\n", max(d[N][B][0], d[N][B][1]));

	return 0;
}
