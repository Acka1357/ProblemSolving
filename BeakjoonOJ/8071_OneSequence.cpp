#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10000];

int main()
{
	int N, S; scanf("%d %d", &N, &S);
	int sign = (S < 0 ? -1 : 1);
	if(S < 0) S *= -1;

	long long sum = 0;
	for(int i = 1; i < N; i++){
		int n = min(N - i, a[i - 1] + 1);
		if(sum + (n * (2 * a[i - 1] + 3 - n)) / 2 <= S)
			a[i] = a[i - 1] + 1;
		else a[i] = a[i - 1] - 1;
		sum += a[i];
	}

	if(sum != S) return !printf("NIE\n");
	for(int i = 0; i < N; i++)
		printf("%d\n", sign * a[i]);

	return 0;
}
