#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long n[121], pb[41] = {1,}, pt[41] = {1,};
char b[41], t[41];

int main()
{
	for(int i = 1; i < 40; i++)
		pb[i] = pb[i - 1] * 2, pt[i] = pt[i - 1] * 3;

	int T; scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		scanf("%s %s", b, t);

		int bl = strlen(b), tl = strlen(t);
		long long bx = 0, tx = 0;
		for(int i = 0; b[i]; i++){
			bx *= 2;
			bx += b[i] - '0';
		}
		for(int i = 0; t[i]; i++){
			tx *= 3;
			tx += t[i] - '0';
		}

		int ni = 0;
		for(int i = 0; b[i]; i++)
			for(int j = '0'; j <= '1'; j++)
				if(b[i] != j) n[ni++] = bx + pb[bl - i - 1] * (j - b[i]);
		for(int i = 0; t[i]; i++)
			for(int j = '0'; j <= '2'; j++)
				if(t[i] != j) n[ni++] = tx + pt[tl - i - 1] * (j - t[i]);

		sort(n, n + ni);

		for(int i = 1; i < ni; i++)
			if(n[i] == n[i - 1])
				printf("#%d %lld\n", tc, n[i]);
	}
	return 0;
}