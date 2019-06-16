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
#include <set>
#include <map>
using namespace std;

typedef long long ll;

bool chk[101], dead[101];
int ans[101], ins[101][101];

int main()
{
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &ins[i][j]);

	for(int m = 1; m <= M; m++){
		int use[101] = {0,};
		for(int i = 1; i <= N; i++){
			if(dead[i] || !ins[i][m]) continue;
			if(chk[ins[i][m]] || use[ins[i][m]]){
				dead[i] = dead[use[ins[i][m]]] = true;
				chk[ins[i][m]] = true;
				ans[i] = ans[use[ins[i][m]]] = m;
			}
			else use[ins[i][m]] = i;
		}
	}

	for(int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);

	return 0;
}
