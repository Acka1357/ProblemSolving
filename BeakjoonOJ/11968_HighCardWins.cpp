#include <stdio.h>
#include <algorithm>
using namespace std;

int e[50000], b[50000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &e[i]);

	sort(e, e + N);

	int idx = 0;
	for(int i = 1; i < e[0]; i++) b[idx++] = i;
	for(int i = 1; i < N; i++)
		for(int j = e[i - 1] + 1; j < e[i]; j++)
			b[idx++] = j;
	for(int i = e[N - 1] + 1; i <= 2 * N; i++) b[idx++] = i;

	int ans = 0, i1 = N - 1, i2 = N - 1;
	while(0 <= i1 && 0 <= i2){
		if(e[i1] > b[i2]) i1--;
		else i1--, i2--, ans++;
	}

	printf("%d\n", ans);
	return 0;
}