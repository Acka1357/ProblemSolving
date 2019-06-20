#include <cstdio>
#include <algorithm>
using namespace std;

int a[30001], d[30001][2];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	for(int i = 1; i <= N; i++){
		d[i][0] = d[i - 1][0] + (a[i] == 2);
		d[i][1] = min(d[i - 1][0], d[i - 1][1]) + (a[i] == 1);
	}
	printf("%d\n", min(d[N][0], d[N][1]));

	return 0;
}