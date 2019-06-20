#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int d[1002][1002];
char a[1002], b[1002];

int main()
{
	scanf("%s %s", a + 1, b + 1);

	memset(d, 0x3f, sizeof(d));
	int la = strlen(a + 1), lb = strlen(b + 1);
	d[0][0] = 0;
	for(int i = 1; i <= la; i++)
		for(int j = 1; j <= lb; j++){
			d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1;
			d[i][j] = min(d[i][j], d[i - 1][j - 1] + (a[i] != b[j]));
			if(i > 1 && j > 1 && a[i] == b[j - 1] && a[i - 1] == b[j])
				d[i][j] = min(d[i][j], d[i - 2][j - 2] + (a[i] != b[j]));
		}

	printf("%d\n", d[la][lb]);
	return 0;
}