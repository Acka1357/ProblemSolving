#include <stdio.h>
#include <algorithm>
using namespace std;

#define PAL_COUNT 199

char s[6];
int p[PAL_COUNT], ans[3];

int main()
{
	setbuf(stdout, NULL);

	int pcnt = 0;
	for(int i = 0; i < 10000; i++){
		int n = i, len;
		for(len = 0; n; n /= 10)
			s[len++] = n % 10;
		bool isp = true;
		for(int j = len / 2; j >= 0; j--)
			if(s[j] != s[len - j - 1]) isp = false;
		if(isp) p[pcnt++] = i;
	}

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N; scanf("%d", &N);

		bool find = false;
		for(int i = 0; i < pcnt && !find; i++)
			for(int j = i; j < pcnt && !find; j++)
				for(int k = j; k < pcnt && !find; k++)
					if(p[i] + p[j] + p[k] == N){
						ans[0] = p[i], ans[1] = p[j], ans[2] = p[k];
						find = true;
					}

		int acnt = 3 - ((ans[0] == 0) + (ans[1] == 0) + (ans[2] == 0));
		printf("Case #%d\n%d", tc, acnt);
		for(int a = 2; acnt--; a--)
			printf(" %d", ans[a]);
		printf("\n");
	}
	return 0;
}