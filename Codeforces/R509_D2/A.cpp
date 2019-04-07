#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a, a + N);

	printf("%d\n", a[N - 1] - a[0] - N + 1);
	return 0;
}