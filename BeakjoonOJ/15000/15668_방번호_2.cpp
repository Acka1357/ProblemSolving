#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool chk1[10], chk2[10];

bool digit(int x, bool *chk){
	for(int i = 0; i < 10; i++)
		chk[i] = false;
	while(x){
		if(chk[x % 10]) return false;
		chk[x % 10] = true;
		x /= 10;
	}
	return true;
}

bool psb(){
	for(int i = 0; i < 10; i++)
		if(chk1[i] & chk2[i])
			return false;
	return true;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = min(98765, N - 1); i > 0; i--)
		if(digit(i, chk1) && digit(N - i, chk2)){
			if(psb()) return !printf("%d + %d\n", i, N - i);
		}
	printf("-1\n");

	return 0;
}
