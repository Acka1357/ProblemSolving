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

bool chk[200001];
int a[200001], b[200001];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++)
		scanf("%d", &b[i]);

	for(int i = 1, cur = 1; i <= N; i++){
		int ans = 0;
		while(!chk[b[i]]){
			chk[a[cur++]] = true;
			ans++;
		}
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}
