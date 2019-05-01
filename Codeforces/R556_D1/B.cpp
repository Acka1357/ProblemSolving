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

const int INF = 0x3f3f3f3f;

char org[100002], s[3][252];
int d[252][252][252], nxt[100002][26];

int main()
{
	memset(d, 0x3f, sizeof(d));

	int N, Q; scanf("%d %d %s", &N, &Q, org + 1);
	for(int i = 0; i < 26; i++)
		nxt[0][i] = INF;
	for(int i = N; i > 0; i--){
		for(int j = 0; j < 26; j++)
			nxt[i][j] = nxt[0][j];
		nxt[0][org[i] - 'a'] = i;
	}

	d[0][0][0] = 0;
	char cmd, alp; int ri, l[3] = {0, 0, 0};
	while(Q--){
		scanf(" %c %d", &cmd, &ri); ri--;
		if(cmd == '+'){
			scanf(" %c", &alp);
			s[ri][++l[ri]] = alp;
			if(ri == 0){
				int i = l[0];
				for(int j = 0; j <= l[1]; j++)
					for(int k = 0; k <= l[2]; k++){
						d[i][j][k] = INF;
						if(i && d[i - 1][j][k] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i - 1][j][k]][s[0][i] - 'a']);
						if(j && d[i][j - 1][k] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i][j - 1][k]][s[1][j] - 'a']);
						if(k && d[i][j][k - 1] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i][j][k - 1]][s[2][k] - 'a']);
					}
			}
			else if(ri == 1){
				int j = l[1];
				for(int i = 0; i <= l[0]; i++)
					for(int k = 0; k <= l[2]; k++){
						d[i][j][k] = INF;
						if(i && d[i - 1][j][k] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i - 1][j][k]][s[0][i] - 'a']);
						if(j && d[i][j - 1][k] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i][j - 1][k]][s[1][j] - 'a']);
						if(k && d[i][j][k - 1] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i][j][k - 1]][s[2][k] - 'a']);
					}
			}
			else if(ri == 2){
				int k = l[2];
				for(int i = 0; i <= l[0]; i++)
					for(int j = 0; j <= l[1]; j++){
						d[i][j][k] = INF;
						if(i && d[i - 1][j][k] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i - 1][j][k]][s[0][i] - 'a']);
						if(j && d[i][j - 1][k] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i][j - 1][k]][s[1][j] - 'a']);
						if(k && d[i][j][k - 1] < INF) d[i][j][k] = min(d[i][j][k], nxt[d[i][j][k - 1]][s[2][k] - 'a']);
					}
			}
			// if(d[l[0]][l[1]][l[2]] < INF && nxt[d[l[0]][l[1]][l[2]]][alp - 'a'] < INF){
			// 	d[l[0] + (ri == 0)][l[1] + (ri == 1)][l[2] + (ri == 2)] = nxt[d[l[0]][l[1]][l[2]]][alp - 'a'];
			// 	s[ri][++l[ri]] = alp;
			// }
			// else{
			// 	s[ri][++l[ri]] = alp;
			// 	memset(d, 0x3f, (l[0] + 1) * sizeof(d[0]));
			// 	d[0][0][0] = 0;
			// 	for(int i = 0; i <= l[0]; i++)
			// 		for(int j = 0; j <= l[1]; j++)
			// 			for(int k = 0; k <= l[2]; k++){
			// 				if(d[i][j][k] >= INF) break;
			// 				if(i < l[0]) d[i + 1][j][k] = min(d[i + 1][j][k], nxt[d[i][j][k]][s[0][i + 1] - 'a']);
			// 				if(j < l[1]) d[i][j + 1][k] = min(d[i][j + 1][k], nxt[d[i][j][k]][s[1][j + 1] - 'a']);
			// 				if(k < l[2]) d[i][j][k + 1] = min(d[i][j][k + 1], nxt[d[i][j][k]][s[2][k + 1] - 'a']);
			// 			}
			// }
		}
		else s[ri][l[ri]--] = 0;
		printf("%s\n", d[l[0]][l[1]][l[2]] < INF ? "YES" : "NO");
	}

	return 0;
}
