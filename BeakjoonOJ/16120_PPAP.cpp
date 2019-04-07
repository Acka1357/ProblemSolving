#include <stdio.h>
#include <string.h>

char st[1000001];
char s[1000001];

int main()
{
	scanf("%s", s);

	int len = strlen(s), top = 0;
	if(len < 4 || s[0] != 'P') return !printf("NP\n");
	
	for(int i = 0; i < len; i++){
		while(top > 3 && st[top - 4] == 'P' && st[top - 3] == 'P' && st[top - 2] == 'A' && st[top - 1] == 'P')
			top -= 3;
		st[top++] = s[i];
	}	
	while(top > 3 && st[top - 4] == 'P' && st[top - 3] == 'P' && st[top - 2] == 'A' && st[top - 1] == 'P')
		top -= 3;

	printf("%s\n", (top == 1 && st[0] == 'P') ? "PPAP" : "NP");
	return 0;
}