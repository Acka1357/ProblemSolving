#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

char s[100001];
int cnt[26];

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	scanf("%s", s);

	for(int i = 0; i < N; i++)
		cnt[s[i] - 'A']++;

	int ans = N;
	for(int i = 0; i < K; i++)
		ans = min(ans, cnt[i]);

	printf("%d\n", ans * K);

	return 0;
}
