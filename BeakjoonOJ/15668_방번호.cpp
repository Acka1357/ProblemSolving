#include <stdio.h>

bool is_ok(int n){
	bool chk[10] = {false};
	if(n == 0) return false;
	while(n){
		if(chk[n % 10]) return false;
		chk[n % 10] = true;
		n /= 10;
	}
	return true;
}

bool is_safe(int a, int b){
	bool chk[10] = {false};
	while(a){
		if(chk[a % 10]) return false;
		chk[a % 10] = true;
		a /= 10;
	}
	while(b){
		if(chk[b % 10]) return false;
		chk[b % 10] = true;
		b /= 10;
	}
	return true;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = (N > 98765 ? 98765 : N); i > 0; i--){
		if(!is_ok(i) || !is_ok(N - i)) continue;
		if(is_safe(i, N - i))
			return !printf("%d + %d\n", i, N - i);
	}
	printf("-1\n");
	return 0;
}