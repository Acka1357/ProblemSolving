#include <cstdio>

int N, L, ans;

bool has(int x){
	while(x){
		if(x % 10 == L) return true;
		x /= 10;
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &L);
	for(int i = ans = 1; i <= N; i++)
		while(has(ans++));
	printf("%d\n", ans - 1);

	return 0;
}