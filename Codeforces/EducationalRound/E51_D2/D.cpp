#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
using namespace std;

#define MOD		998244353

long long d[1000][4][2001];

int main()
{
	int N, K; scanf("%d %d", &N, &K);

	d[0][0][1] = d[0][1][1] = 1;
	d[0][2][2] = d[0][3][2] = 1;
	for(int i = 1; i < N; i++)
		for(int j = 2 * i; j > 0; j--){
			d[i][0][j] = (d[i][0][j] + d[i - 1][0][j]) % MOD;
			d[i][1][j + 1] = (d[i][1][j + 1] + d[i - 1][0][j]) % MOD;
			d[i][2][j + 1] = (d[i][2][j + 1] + d[i - 1][0][j]) % MOD;
			d[i][3][j + 1] = (d[i][3][j + 1] + d[i - 1][0][j]) % MOD;

			d[i][0][j + 1] = (d[i][0][j + 1] + d[i - 1][1][j]) % MOD;
			d[i][1][j] = (d[i][1][j] + d[i - 1][1][j]) % MOD;
			d[i][2][j + 1] = (d[i][2][j + 1] + d[i - 1][1][j]) % MOD;
			d[i][3][j + 1] = (d[i][3][j + 1] + d[i - 1][1][j]) % MOD;

			d[i][0][j] = (d[i][0][j] + d[i - 1][2][j]) % MOD;
			d[i][1][j] = (d[i][1][j] + d[i - 1][2][j]) % MOD;
			d[i][2][j] = (d[i][2][j] + d[i - 1][2][j]) % MOD;
			d[i][3][j + 2] = (d[i][3][j + 2] + d[i - 1][2][j]) % MOD;

			d[i][0][j] = (d[i][0][j] + d[i - 1][3][j]) % MOD;
			d[i][1][j] = (d[i][1][j] + d[i - 1][3][j]) % MOD;
			d[i][2][j + 2] = (d[i][2][j + 2] + d[i - 1][3][j]) % MOD;
			d[i][3][j] = (d[i][3][j] + d[i - 1][3][j]) % MOD;
		}

	long long ans = 0;
	for(int i = 0; i < 4; i++)
		ans = (ans + d[N - 1][i][K]) % MOD;
	printf("%lld\n", ans);

	return 0;
}
