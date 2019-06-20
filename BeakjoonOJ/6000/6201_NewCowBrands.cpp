#include <cstdio>

int N, S, E, st[17], top, cnt;
char s[16][27], ans[27];
bool chk[256];

void make(int cur){
	if(E <= cnt) return ;
	if(cur == N){
		cnt++;
		if(S <= cnt && cnt <= E) printf("%s\n", ans);
		return ;
	}

	for(int i = 0; s[cur][i]; i++)
		if(!chk[s[cur][i]]){
			chk[s[cur][i]] = true;
			ans[cur] = s[cur][i];
			make(cur + 1);
			chk[s[cur][i]] = false;
		}
}

int main()
{
	scanf("%d %d %d", &N, &S, &E);
	for(int i = 0; i < N; i++)
		scanf("%s", s[i]);

	make(0);

	return 0;
}
