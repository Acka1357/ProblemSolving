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

char cmd[200002];
int N, cum[200001][4], gx, gy, ex, ey, ad[256], cumx[200001], cumy[200001], needx, needy;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

int absx(int x){
	return x < 0 ? -x : x;
}

bool psb(int len){
	for(int l = 1, r = len; r <= N; l++, r++){
		needx = absx(cumx[N] - cumx[r] + cumx[l - 1] - gx);
		needy = absx(cumy[N] - cumy[r] + cumy[l - 1] - gy);
		if(needx + needy <= len && ((needx + needy) & 1) == (len & 1)){
		 	// printf("[%d, %d]: %d\n", l, r, len);
			return true;
		}
	}
	return false;
}
int main()
{
	ad['U'] = 0; ad['D'] = 1; ad['L'] = 2; ad['R'] = 3;
	scanf("%d %s %d %d", &N, cmd + 1, &gx, &gy);
	for(int i = 1; i <= N; i++){
		cmd[i] = ad[cmd[i]];
		ex += dx[cmd[i]];
		ey += dy[cmd[i]];
		for(int j = 0; j < 4; j++)
			cum[i][j] = cum[i - 1][j];
		cum[i][cmd[i]]++;
		cumx[i] = cumx[i - 1] + dx[cmd[i]];
		cumy[i] = cumy[i - 1] + dy[cmd[i]];
	}
	if(gx == ex && gy == ey) return !printf("0\n");

	int l = 1, r = N, m, ans = -1;
	while(l <= r){
		m = (l + r) / 2;
		if(psb(m)){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	printf("%d\n", ans);
	return 0;
}
