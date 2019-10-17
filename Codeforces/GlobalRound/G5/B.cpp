#include <cstdio>

int a[200005], ai[200005], b[200005], ans;

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		ai[a[i]] = i;
	}

	for(int i = 0; i < N; i++)
		scanf("%d", &b[i]);

	int mini = N + 1;
	for(int i = N - 1; i >= 0; i--){
		if(mini < ai[b[i]]) ans++;
		if(ai[b[i]] < mini) mini = ai[b[i]];
	}
	printf("%d\n", ans);

	return 0;
}