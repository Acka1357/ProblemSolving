#include <cstdio>
#include <algorithm>
using namespace std;

char s[3];
int N, scr[256], d[8][8];

int main()
{
	for(int i = '2'; i <= '9'; i++)
		scr[i] = i - '0';
	scr['A'] = 1; scr['T'] = 10;
	scr['J'] = 11; scr['Q'] = 12; scr['K'] = 13;

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 1; j <= N; j++){
			scanf("%s", s);
			d[N - i][j] = scr[s[0]];
		}

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			d[i][j] += max(d[i - 1][j], d[i][j - 1]);
	printf("%d\n", d[N][N]);

	return 0;
}