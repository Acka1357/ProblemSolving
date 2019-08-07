#include <cstdio>

char t[256];
char map[257][257], ans[257][257];

int main()
{
	t['-'] = '|';
	t['|'] = '-';
	t['/'] = '\\';
	t['\\'] = '/';
	t['^'] = '<';
	t['<'] = 'v';
	t['v'] = '>';
	t['>'] = '^';

	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%s", map[i]);
		for(int j = 0; j < M; j++)
			ans[M - j - 1][i] = t[map[i][j]] ? t[map[i][j]] : map[i][j];
	}

	for(int i = 0; i < M; i++)
		printf("%s\n", ans[i]);

	return 0;
}