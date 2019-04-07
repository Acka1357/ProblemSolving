// solution:
// 양 끝을 비교하며 더 작은 쪽이 먼저 오도록 출력한다.
// 이때 양 끝 문자가 같다면 다음 문자가 서로 달라질 때까지 비교하며
// 더 작은쪽이 먼저 오는 문자를 먼저 출력한다.

// 시간복잡도: O(N^2)
// 분류: Greedy
// 난이도: 1250 ~ 1500

#include <cstdio>

char s[2001];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf(" %c", &s[i]);

	int l = 0, r = N - 1;
	for(int i = 0; i < N; i++){
		if(i && !(i % 80)) printf("\n");
		if(s[l] == s[r]){
			bool chk = false;
			for(int j = 1; j <= (r - l) / 2; j++){
				if(s[l + j] == s[r - j]) continue;
				if(s[l + j] < s[r - j]) printf("%c", s[l++]);
				else printf("%c", s[r--]);
				chk = true; break;
			}
			if(!chk) printf("%c", s[l++]);
		}
		else if(s[l] < s[r]) printf("%c", s[l++]);
		else printf("%c", s[r--]);
	}
	printf("\n");

	return 0;
}
