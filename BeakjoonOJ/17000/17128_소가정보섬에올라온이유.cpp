#include <cstdio>

int N, Q, idx, a[200000], cur;

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < N; i++)
		cur += a[i] * a[(i + 1) % N] * a[(i + 2) % N] * a[(i + 3) % N];

	while(Q--){
		scanf("%d", &idx);
		int tmp = 1;
		for(int i = 0; i < 4; i++)
			tmp *= a[(idx + i) % N];
		cur -= 2 * tmp;
		a[i] *= -1;
		printf("%d\n", cur);
	}
	return 0;
}