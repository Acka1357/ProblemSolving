#include <stdio.h>
#include <assert.h>

int main()
{
	int q; scanf("%d", &q);
	if(q == 1) puts("65");
	else if(q == 2) assert(false);
	else if(q == 3) while(true);
	else if(q == 4) { for(int i = 0; i < 10; i++) printf("0\n"); }
	else puts("64");
	return 0;
}
