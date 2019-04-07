#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Crd{ int r, c, bi; };

bool block[][4][4] = { {{1, 1}, {1}, {1}}, {{1}, {1, 1, 1}},
		{{0, 1}, {0, 1}, {1, 1}}, {{1, 1, 1}, {0, 0, 1}},
		{{1, 1}, {0, 1}, {0, 1}}, {{0, 0, 1}, {1, 1, 1}},
		{{1}, {1}, {1, 1}}, {{1, 1, 1}, {1}}, {{1}, {1}, {1}, {1}},
		{{1, 1, 1, 1}}, {{1, 1}, {1, 1}}, {{1}, {1, 1}, {1}}, {{0, 1}, {1, 1, 1}},
		{{0, 1}, {1, 1}, {0, 1}}, {{1, 1, 1}, {0, 1}}, {{1}, {1, 1}, {0, 1}},
		{{0, 1, 1}, {1, 1}}, {{0, 1}, {1, 1}, {1}}, {{1, 1}, {0, 1, 1}} };  
bool map[20][10], chk[24][10][19];
int dr[3] = {1, 0, 0}, dc[3] = {0, 1, -1};
char s[11];

int psb(int r, int c, bool b[][4]){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++){
			if(!b[i][j]) continue;
			if(c + j < 0 || c + j >= 10) return -1;
			if(r + i >= 20) return 0;
			if(map[r + i][c + j]) return 0;
		}
	return 1;
}

int hmany(int r, int c, bool b[][4]){
	int sum = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(b[i][j]) map[r + i][c + j] = true;
	for(int i = 0; i < 20; i++){
		bool fill = true;
		for(int j = 0; j < 10; j++)
			if(!map[i][j]) fill = false;
		sum += fill;
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(b[i][j]) map[r + i][c + j] = false;
	return sum;
}

int main()
{
	for(int i = 0; i < 20; i++){
		scanf("%s", s);
		for(int j = 0; j < 10; j++)
			map[i][j] = (s[j] == '1');
	}

	queue<Crd> q;
	for(int i = 0; i < 19; i++){
		q.push({0, 0, i});
		chk[i][0][0] = true;
	}

	int ans = 0;
	while(!q.empty()){
		int r = q.front().r, c = q.front().c, bi = q.front().bi; q.pop();
		for(int i = 0; i < 3; i++){
			int nr = r + dr[i], nc = c + dc[i];
			int res = psb(nr, nc, block[bi]);
			if(res < 0 || chk[nr][nc][bi]) continue;
			if(res == 1){
				q.push({nr, nc, bi});
				chk[nr][nc][bi] = true;
			}
			else if(!i) ans = max(ans, hmany(r, c, block[bi]));
		}
	}
	printf("%d\n", ans);

	return 0;
}