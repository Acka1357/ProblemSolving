#include <cstdio>

bool chk(int x){
	bool use[10] = {0,};
	while(x){
		if(use[x % 10]) return false;
		use[x % 10] = true;
		x /= 10;
	}
	return true;
}

int main()
{
	int L, R; scanf("%d %d", &L, &R);
	for(int i = L; i <= R; i++)
		if(chk(i)) return !printf("%d\n", i);
	printf("-1\n");
	return 0;
}