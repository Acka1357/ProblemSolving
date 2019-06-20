#include <cstdio>

int N, K, ans;
bool on[100001], rev[100001], tog;

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0, x; i < N; i++)
		scanf("%d", &x), on[i] = x;
	for(int i = 0; i < N; i++){
		if(rev[i]) tog = !tog;
		if(on[i] != tog){
			if(i > N - K) return !printf("Insomnia\n");
			tog = !tog, rev[i + K] = true;
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
