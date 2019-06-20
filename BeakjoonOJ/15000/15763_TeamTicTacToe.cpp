#include <stdio.h>

int rcnt[3][26], ccnt[3][26], dcnt[2][26];
char map[3][4];

int main()
{
	for(int i = 0; i < 3; i++)
		scanf("%s", map[i]);

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++){
			rcnt[i][map[i][j] - 'A']++;
			ccnt[j][map[i][j] - 'A']++;
			if(i == j) dcnt[0][map[i][j] - 'A']++;
			if(i + j == 2) dcnt[1][map[i][j] - 'A']++;
		}

	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < 26; i++){
		bool chk = (dcnt[0][i] == 3 || dcnt[1][i] == 3);
		for(int j = 0; j < 3; j++)
			if(rcnt[j][i] == 3 || ccnt[j][i] == 3) chk = true;
		ans1 += chk;
	}
	for(int i = 0; i < 26; i++)
		for(int j = i + 1; j < 26; j++){
			bool chk = false;
			for(int k = 0; k < 2; k++){
				if(!dcnt[k][i] || !dcnt[k][j]) continue;
				chk |= (dcnt[k][i] + dcnt[k][j] == 3);
			}
			for(int k = 0; k < 3; k++){
				if(!rcnt[k][i] || !rcnt[k][j]) continue;
				chk |= (rcnt[k][i] + rcnt[k][j] == 3);
			}
			for(int k = 0; k < 3; k++){
				if(!ccnt[k][i] || !ccnt[k][j]) continue;
				chk |= (ccnt[k][i] + ccnt[k][j] == 3);
			}
			ans2 += chk;
		}
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}