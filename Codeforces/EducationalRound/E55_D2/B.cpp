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

char s[100003];
int segl[100003];
bool isgold[100003];

int main()
{
	int N; scanf("%d %s", &N, s);

	int cnt = 1, goldcnt = (s[0] == 'G');
	isgold[0] = (s[0] == 'G');
	segl[0] = 1;
	for(int i = 1; i < N; i++){
		if(s[i] == 'G') goldcnt++;
		if(s[i] == s[i - 1])
			segl[cnt - 1]++;
		else{
			isgold[cnt] = (s[i] == 'G');
			segl[cnt++] = 1;
		}
	}

	int ans = 0;
	for(int i = 0; i < cnt; i++){
		if(isgold[i]) ans = max(ans, segl[i]);
		else{
			if(i && i < cnt - 1 && segl[i] == 1)
				ans = max(ans, segl[i - 1] + segl[i + 1]);
			if(i && i < cnt - 1 && segl[i] == 1 && segl[i - 1] + segl[i + 1] != goldcnt)
				ans = max(ans, segl[i - 1] + segl[i + 1] + 1);
			if(i && segl[i - 1] != goldcnt) ans = max(ans, segl[i - 1] + 1);
			if(i < cnt - 1 && segl[i + 1] != goldcnt) ans = max(ans, segl[i + 1] + 1);
		}
	}

	printf("%d\n", ans);
	return 0;
}
