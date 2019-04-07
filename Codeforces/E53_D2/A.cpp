#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
using namespace std;

int cnt[1001][256];
char s[1001];

int main()
{
	int N; scanf("%d %s", &N, s);
	for(int i = 1; i <= N; i++){
		cnt[i][s[i - 1]]++;
		for(int j = 'a'; j <= 'z'; j++)
			cnt[i][j] += cnt[i - 1][j];
	}
	
	for(int i = 1; i <= N; i++)
		for(int j = i; j <= N; j++){
			bool chk = true;
			for(int k = 'a'; k <= 'z'; k++)
				if(cnt[j][k] - cnt[i - 1][k] > (j - i + 1) / 2)
					chk = false;
			if(chk){
				printf("YES\n");
				for(int k = i - 1; k < j; k++)
					printf("%c", s[k]);
				return !printf("\n");
			}
		}

	printf("NO\n");
	return 0;
}
