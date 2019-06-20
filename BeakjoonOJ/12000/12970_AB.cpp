#include <cstdio>

char s[51];

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		s[i] = 'B';
	for(int i = 0; i < N; i++){
		if(K > (i + 1) * (N - i - 1)) s[i] = 'A';
		else{
			s[N - (K - i * (N - i - 1)) - 1] = 'A';
			return !printf("%s\n", s);
		}
	}
	return !printf("-1\n");
}
