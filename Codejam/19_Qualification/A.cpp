#include <cstdio>
#include <cstring>

char s[101], a[101], b[101];

int main()
{
	int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
		scanf("%s", s);
		strcpy(a, s);
		memset(b, '0', sizeof(b));
		int len = strlen(s);
		bool chk = false;
		b[len] = 0;
		for(int i = 0; i < len; i++)
			if(s[i] == '4'){
				a[i]--; b[i] = '1';
				chk = true;
			}
		if(chk){
			printf("Case #%d: %s ", tc, a);
			int bi = 0; while(b[bi] == '0') bi++;
			while(b[bi]) printf("%c", b[bi++]);
			printf("\n");
		}
		else{
			int t = 1 + (s[len - 1] == '5');
			a[len - 1] -= t;
			printf("Case #%d: %s %d\n", tc, a, t);
		}
	}
	return 0;
}