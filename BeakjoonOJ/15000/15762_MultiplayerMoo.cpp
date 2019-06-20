#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int map[250][250], N, chk[250][250], chkn;
bool dchk[250][250][4], chk1[250][250];

int count1(int r, int c){
	queue<int> qr, qc;
	chk1[r][c] = true;
	int sum = 0;
	qr.push(r); qc.push(c);
	while(!qr.empty()){
		r = qr.front(); c = qc.front(); qr.pop(); qc.pop();
		sum++;
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if(chk1[nr][nc] || map[nr][nc] != map[r][c]) continue;
			chk1[nr][nc] = true;
			qr.push(nr); qc.push(nc);
		}
	}
	return sum;
}

int count(int r, int c, int a, int b){
	queue<int> qr, qc;
	int sum = 0;
	chk[r][c] = ++chkn;
	qr.push(r); qc.push(c);
	while(!qr.empty()){
		r = qr.front(); c = qc.front(); qr.pop(); qc.pop();
		sum++;
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i], nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if(map[nr][nc] != a && map[nr][nc] != b) continue;
			if(chk[nr][nc] == chkn) continue;
			chk[nr][nc] = chkn;
			dchk[r][c][i] = dchk[nr][nc][(i + 2) % 4] = true;
			qr.push(nr); qc.push(nc);
		}
	}
	return sum;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(!chk1[i][j]) ans1 = max(ans1, count1(i, j));

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			if(j < N - 1 && map[i][j] != map[i][j + 1] && !dchk[i][j][0])
				ans2 = max(ans2, count(i, j, map[i][j], map[i][j + 1]));
			if(i < N - 1 && map[i][j] != map[i + 1][j] && !dchk[i][j][1])
				ans2 = max(ans2, count(i, j, map[i][j], map[i + 1][j]));
		}

	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
