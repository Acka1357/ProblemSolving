#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
int R, C, h[500][500], comp, leaf;
bool chk[500][500];

int main()
{
	scanf("%d %d", &C, &R);
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			scanf("%d", &h[i][j]);

	queue<int> qr, qc;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			if(chk[i][j]) continue;
			qr.push(i); qc.push(j);
			chk[i][j] = true;
			int minv = 10000, maxv = -1;
			while(!qr.empty()){
				int r = qr.front(), c = qc.front(); qr.pop(); qc.pop();
				for(int k = 0; k < 4; k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
					if(!chk[nr][nc] && h[nr][nc] == h[r][c]){
						chk[nr][nc] = true;
						qr.push(nr); qc.push(nc);
					}
					if(h[nr][nc] != h[r][c]){
						maxv = max(maxv, h[nr][nc]);
						minv = min(minv, h[nr][nc]);
					}
				}
			}
			if(maxv > -1 && maxv < h[i][j]) comp++;
			if(minv < 10000 && minv > h[i][j]) leaf++;
		}

	printf("%d\n", max(comp, leaf));

	return 0;
}
