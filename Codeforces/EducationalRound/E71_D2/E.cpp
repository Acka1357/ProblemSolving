#include <cstdio>
#include <cstdlib>

int main()
{
	int f, t;
	printf("? ");
	for(int i = 1; i <= 100; i++)
		printf("%d%c", i, " \n"[i == 100]);
	fflush(stdout);
	scanf("%d", &f);

	printf("? ");
	for(int i = 1; i <= 100; i++)
		printf("%d%c", i << 7, " \n"[i == 100]);
	fflush(stdout);
	scanf("%d", &t);

	printf("! %d\n", ((f >> 7) << 7) | (t % 128));
	fflush(stdout);

	return 0;
}