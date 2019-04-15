#include <cstdio>

int s[10001];

int main()
{
	int N, T; scanf("%d %d", &N, &T);
	for(int i = 1; i <= N; i++)
		scanf("%d", &s[i]);

	while(T--){
		int pick = -1, ps = -1;
		for(int i = 1; i <= N; i++)
			if(s[i] > ps){
				pick = i; ps = s[i];
			}

		int add = ps / (N - 1), rem = ps % (N - 1);
		for(int i = 1; i <= N; i++)
			if(i != pick){
				s[i] += add;
				if(rem) s[i]++, rem--; 
			} 
		s[pick] = 0;
		printf("%d\n", pick);
	}
	return 0;
}