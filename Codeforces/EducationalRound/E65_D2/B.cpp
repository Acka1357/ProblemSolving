#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

bool chk[6];
int a[] = {4, 8, 15, 16, 23, 42};
int ans[6], m[6];

bool dfs(int cur){
	if(cur == 6){
		for(int i = 1; i < 5; i++)
			if(ans[i] * ans[i - 1] != m[i])
				return false;
		printf("! %d %d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);
		return true;
	}
	for(int i = 0; i < 6; i++)
		if(!chk[i]){
			chk[i] = true;
			ans[cur] = a[i];
			if(dfs(cur + 1)) return true;
			chk[i] = false;
		}
	return false;
}

int main()
{
	printf("? 1 2\n"); fflush(stdout);
	scanf("%d", &m[1]);
	printf("? 2 3\n"); fflush(stdout);
	scanf("%d", &m[2]);
	printf("? 3 4\n"); fflush(stdout);
	scanf("%d", &m[3]);
	printf("? 4 5\n"); fflush(stdout);
	scanf("%d", &m[4]);

	dfs(0);
	fflush(stdout);
	
	return 0;
}
