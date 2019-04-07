#include <stdio.h>
#include <algorithm>
using namespace std;

struct Cow{
	int n; bool spot;
	bool operator <(const Cow &o)const{
		return n < o.n;
	}
};

char s[3];
Cow cow[50002];

int main()
{
	int N, A, B; scanf("%d %d %d", &N, &A, &B);
	for(int i = 1; i <= N; i++){
		scanf("%s %d", s, &cow[i].n);
		cow[i].spot = (s[0] != 'N');
	}

	cow[0].n = -2100000000;	cow[N + 1].n = -cow[0].n;
	sort(cow + 1, cow + N + 1);

	long long ans = 0, len, mid;
	for(int i = 0; i <= N; i++){
		if(B < cow[i].n || A > cow[i + 1].n) continue;

		len = cow[i + 1].n - cow[i].n;
		mid = ((long long)cow[i].n + cow[i + 1].n) / 2;
		if(mid < A) ans += cow[i + 1].spot * (B <= cow[i + 1].n ? B - A + 1 : cow[i + 1].n - A + 1);
		else if(B < mid) ans += cow[i].spot * (cow[i].n < A ? B - A + 1 : B - cow[i].n);
		else if(len & 1) ans += cow[i].spot * (mid - (cow[i].n < A ? A - 1 : cow[i].n)) + cow[i + 1].spot * (min(cow[i + 1].n, B) - mid);
		else ans += cow[i].spot * (mid - max(cow[i].n, A) - 1) + cow[i + 1].spot * (min(cow[i + 1].n, B) - mid) + (cow[i].spot | cow[i + 1].spot);
	}

	printf("%lld\n", ans);
	return 0;
}