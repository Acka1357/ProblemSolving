#include <cstdio>
#include <algorithm>
using namespace std;

int t[100];
bool chk[2000001];

int main()
{
	int N, C; scanf("%d %d", &N, &C);
	for(int i = 0; i < N; i++)
		scanf("%d", &t[i]);

	sort(t, t + N);

	for(int i = 0; i < N; i++){
		bool mul = false;
		for(int j = 0; j < i; j++)
			if(t[j] % t[i] == 0) mul = true;
		if(mul) continue;
		for(int j = t[i]; j <= C; j += t[i])
			chk[j] = true;
	}

	int ans = 0;
	for(int i = 0; i <= C; i++)
		ans += chk[i];
	printf("%d\n", ans);

	return 0;
}
