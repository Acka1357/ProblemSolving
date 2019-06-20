/*
	2019 Ajou Univ. Programming Contest
	APC는 왜 서브태스크 대회가 되었을까? - 서브태스크2
	Acka's cpp solution
	Time Complexity: O(N)
*/

#include <cstdio>

int main()
{
	int N, L, K; scanf("%d %d %d", &N, &L, &K);
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0, s, l; i < N; i++){
		scanf("%d %d", &s, &l);
		if(l <= L) cnt1++, cnt2++;
		else if(s <= L) cnt2++;
	}

	if(K < cnt1) cnt1 = K;
	if(K < cnt2) cnt2 = K;
	printf("%d\n", cnt2 * 100 + cnt1 * 40);

	return 0;
}
