/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - pattern
	Time Complexity: O(L)
*/

#include <cstdio>

int absx(int x){ return x < 0 ? -x : x; }

bool chk[10];

int main()
{
	int L, a[9]; scanf("%d", &L);
	for(int i = 0; i < L; i++)
		scanf("%d", &a[i]);

	chk[a[0]] = true;
	for(int i = 1; i < L; i++){
		if(chk[a[i]]) return !printf("NO\n");
		chk[a[i]] = true;

		int r1 = (a[i - 1] - 1) / 3, c1 = (a[i - 1] - 1) % 3;
		int r2 = (a[i] - 1) / 3, c2 = (a[i] - 1) % 3;
		if((r1 == r2 && absx(c1 - c2) == 2) ||
			(c1 == c2 && absx(r1 - r2) == 2) ||
			(absx(r1 - r2) == 2 && absx(c1 - c2) == 2)){
			if(!chk[(a[i - 1] + a[i]) / 2])
				return !printf("NO\n");
		}
	}
	printf("YES\n");

	return 0;
}