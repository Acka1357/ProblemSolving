#include <cstdio>

typedef long long ll;

int A, B, C, ans;
bool np[4000001];

bool chk(int x){
	while(x){
		if((x % 10) == C) return true;
		x /= 10;
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &A, &B, &C);
	for(ll i = 2; i <= B; i++){
		if(np[i]) continue;
		if(i >= A) ans += chk(i);
		for(ll j = i * i; j <= B; j += i)
			np[j] = true;
	}
	printf("%d\n", ans);

	return 0;
}
