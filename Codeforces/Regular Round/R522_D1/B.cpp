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

struct Coin{
	int k, cnt;
};

Coin coin[101];
int p[101], d[2][101][10001];

int main()
{
	int N, K = 1, sum = 0; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
		sum += p[i];
	}

	sort(p + 1, p + N + 1);
	coin[1].k = p[1]; coin[1].cnt = 1;
	for(int i = 2; i <= N; i++){
		if(p[i] == p[i - 1]) coin[K].cnt++;
		else{
			coin[K + 1].k = p[i];
			coin[++K].cnt = 1;
		}
	}

	int t = 0, sumc = 0, sump = 0;
	d[0][0][0] = 1;
	for(int i = 1; i <= K; i++, t = !t){
		for(int j = 0; j <= sumc; j++)
			for(int pri = 0; pri <= sump; pri++)
				d[1 - t][j][pri] = d[t][j][pri];
		for(int j = 0; j <= sumc; j++){
			for(int pri = 0; pri <= sump; pri++){
				if(!d[t][j][pri]) continue;
				for(int cnt = 1, addp = coin[i].k; cnt <= coin[i].cnt; cnt++, addp += coin[i].k){
					d[1 - t][j + cnt][pri + addp] += d[t][j][pri];
					if(d[1 - t][j + cnt][pri + addp] > 2) d[1 - t][j + cnt][pri + addp] = 2;
				}
			}
		}
		sumc += coin[i].cnt;
		sump += coin[i].k * coin[i].cnt;
	}

	int ans = 0;
	for(int i = 1; i <= K; i++){
		for(int cnt = 1; cnt <= coin[i].cnt; cnt++){
			if(d[t][cnt][cnt * coin[i].k] == 1){
				// printf("[!] %d %d %d\n", coin[i].k, coin[i].cnt, cnt);
				ans = max(ans, cnt);
			}
			if(d[t][N - cnt][sum - cnt * coin[i].k] == 1){
				// printf("[*] %d %d %d\n", coin[i].k, coin[i].cnt, cnt);
				ans = max(ans, cnt);
			}
		}
		// printf("[%d][%d]:%d [%d][%d]:%d\n", coin[i].cnt, coin[i].cnt * coin[i].k, d[t][coin[i].cnt][coin[i].cnt * coin[i].k], N - coin[i].cnt, sum - coin[i].cnt * coin[i].k, d[t][N - coin[i].cnt][sum - coin[i].cnt * coin[i].k]);
		if(K == 2 && d[t][coin[i].cnt][coin[i].cnt * coin[i].k] == 1 
			&& d[t][N - coin[i].cnt][sum - coin[i].cnt * coin[i].k] == 1)
			ans = N;
	}
	printf("%d\n", ans);

	return 0;
}
