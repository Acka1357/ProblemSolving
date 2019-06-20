#include <cstdio>

int a[10];
bool chk[2301];

int main()
{
	int N, L; scanf("%d %d", &N, &L);
	for(int i = 0; i < L; i++)
		scanf("%d", &a[i]);

	for(int i = 0, sum = N, cur = 1; sum > 1; i++, sum--){
		int find = (a[i % L] - 1) % sum + 1;
		for(; ; cur = (cur % N) + 1){
			if(chk[cur]) continue;
			if(--find == 0){
				chk[cur] = true;
				break;
			}
		}
	}

	for(int i = 1; i <= N; i++)
		if(!chk[i]) printf("%d\n", i);

	return 0;
}
