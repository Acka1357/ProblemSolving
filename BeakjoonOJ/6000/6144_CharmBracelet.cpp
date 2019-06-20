#include <cstdio>

int d[12881];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, w, a; i < N; i++){
		scanf("%d %d", &w, &a);
		for(int j = M; j >= w; j--)
			if(d[j] < d[j - w] + a)
				d[j] = d[j - w] + a;
	}
	printf("%d\n", d[M]);

	return 0;
}