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
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

char map[103][103];
int p[1000006], d[1000006], past[1000006], ans[1000006], mind[103][103];

int main()
{
	memset(mind, 0x3f, sizeof(mind));

	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%s", map[i] + 1);
		for(int j = 1; j <= N; j++)
			if(map[i][j] == '1') mind[i][j] = 1;
	}
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				mind[i][j] = min(mind[i][j], mind[i][k] + mind[k][j]);

	int M; scanf("%d", &M);
	for(int i = 1; i <= M; i++)
		scanf("%d", &p[i]);

	memset(d, 0x3f, sizeof(d));

	d[1] = 1;
	for(int i = 1; i <= M; i++){
		int cur = p[i], len = d[i] + 1;
		// printf("%d %d\n", i, len - 1);
		for(int j = 1; j <= N; j++){
			if(p[i + j] != cur && mind[cur][p[i + j]] == j){
				if(d[i + j] > len){
					d[i + j] = len;
					past[i + j] = i;
				}
			}
			else break;
		}
	}

	int ans_len = d[M];
	ans[ans_len] = p[M];
	for(int i = ans_len - 1, cur = M; i > 0; i--){
		cur = past[cur];
		ans[i] = p[cur];
	}

	printf("%d\n", ans_len);
	for(int i = 1; i <= ans_len; i++)
		printf("%d%c", ans[i], " \n"[i == ans_len]);

	return 0;
}