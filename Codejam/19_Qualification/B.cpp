#include <cstdio>

int main()
{
	int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
		int N; scanf("%d", &N);
		printf("Case #%d: ", tc);
		char c;
		for(int i = 2 * N - 2; i > 0; i--){
			scanf(" %c", &c);
			printf("%c", c == 'S' ? 'E' : 'S');
		}
		printf("\n");
	}
	return 0;
}