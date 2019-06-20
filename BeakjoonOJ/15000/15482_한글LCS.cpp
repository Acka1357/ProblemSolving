#include <stdio.h>
#include <string.h>

char a[3006], b[3006];
int d[1001][1001];

int main()
{
	scanf("%s %s", a + 3, b + 3);

	int la, lb;
	for(la = 0; a[3 * la + 3] | a[3 * la + 4] | a[3 * la + 5]; la++);
	for(lb = 0; b[3 * lb + 3] | b[3 * lb + 4] | b[3 * lb + 5]; lb++);

	for(int i = 1; i <= la; i++)
		for(int j = 1; j <= lb; j++){
			if(a[3 * i] == b[3 * j] && a[3 * i + 1] == b[3 * j + 1] && a[3 * i + 2] == b[3 * j + 2]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = (d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1]);
		}

	printf("%d\n", d[la][lb]);
	return 0;
}