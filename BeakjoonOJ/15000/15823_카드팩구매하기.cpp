// solution:
// 중복되지 않는 K장짜리 카드팩 M묶음을 구매할 때
// i장짜리 카드팩을 M개 구매하는 것이 가능하다면 i 이하에 대해서도 성립하고
// i장짜리 카드팩 M개 구매하는 것이 불가능하다면 i 이상에 대해서도 성립한다.
// 따라서 가능한 가장 큰 K는 바이너리 서치로 구할 수 있다.
// 각 k에 대해 가능/불가능 판단은 앞에서부터 묶을 수 있다면 묶는 것이 최적임을 알 수 있다.
// 그래서 팩 주냐?

// 시간복잡도: O(NlogK)
// 분류: Binary Search, Two Pointer
// 난이도: 1500

#include <cstdio>

int N, M, a[100000], st[500001], tc;

bool psb(int n){
	int curl = 0, cnt = 0; ++tc;
	for(int i = 0; i < N; i++){
		while(st[a[i]] == tc)
			st[a[curl++]] = -1;
		if(curl == i) ++tc;
		st[a[i]] = tc;
		if(i - curl + 1 == n){
			if(++cnt == M) return true;
			curl = i + 1;
			++tc;
		}
	} 
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int l = 1, r = N / M, m, ans = 0;
	while(l <= r){
		m = (l + r) / 2;
		if(psb(m)) ans = m, l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", ans);

	return 0;
}
