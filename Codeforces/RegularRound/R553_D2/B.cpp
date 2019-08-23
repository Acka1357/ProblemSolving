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

struct Status{ int cur, pb; };

int a[501][501], ans[501];
Status d[501][2];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &a[i][j]);

	for(int bi = 0, b = 1; b < 1024; bi++, b <<= 1){
		memset(d, 0xff, sizeof(d));
		d[0][0].cur = d[0][0].pb = 0;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				bool tog = a[i][j] & b;
				if(d[i - 1][0].cur >= 0)
					d[i][0 ^ tog] = {j, 0};
				if(d[i - 1][1].cur >= 0)
					d[i][1 ^ tog] = {j, 1};
			}
		}
		if(d[N][1].cur >= 0){
			printf("TAK\n");
			for(int i = N, cb = 1; i > 0; i--){
				ans[i] = d[i][cb].cur;
				cb = d[i][cb].pb;
			}
			for(int i = 1; i <= N; i++)
				printf("%d%c", ans[i], " \n"[i == N]);
			return 0;
		}
	}

	return !printf("NIE\n");
}
