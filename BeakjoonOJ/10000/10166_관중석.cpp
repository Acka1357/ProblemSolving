#include <stdio.h>

int gcd(int a, int b){
	for(int c; b; ){
		c = a; a = b; b = c % b;
	}
	return a;
}

bool chk[2001][2001];

int main()
{
	int D1, D2; scanf("%d %d", &D1, &D2);

	int ans = 1, g;
	for(int i = D1; i <= D2; i++)
		for(int j = 1; j < i; j++){
			g = gcd(i, j);
			if(!chk[i / g][j / g]) chk[i / g][j / g] = true, ans++;
		}

	printf("%d\n", ans);
	return 0;
}