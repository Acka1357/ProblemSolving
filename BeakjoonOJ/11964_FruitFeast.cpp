#include <stdio.h>

bool can[5000001];

int main()
{
	int T, A, B, ans = 0; scanf("%d %d %d", &T, &A, &B);
	can[0] = true;
	for(int f = 0; f < 2; f++)
	for(int i = 0; i <= T; i++)
		if(can[i]){
			if(!f) can[i / 2] = true, ans = (ans > i / 2) ? ans : i / 2;
			else ans = ans > i ? ans : i;
			if(i + A <= T) can[i + A] = true;
			if(i + B <= T) can[i + B] = true;
		}

	printf("%d\n", ans);
	return 0;
}