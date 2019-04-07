#include <stdio.h>
#include <string.h>

int D, len;
char P[31];

int calc_socre(){
	int sc = 0, v = 1;
	for(int i = 0; P[i]; i++){
		if(P[i] == 'S') sc += v;
		else v *= 2;
	}
	return sc;
}

bool drag_c(){
	bool f = false;
	for(int i = len - 1; i >= 0; i--){
		if(P[i] == 'C' && f){
			P[i] = 'S';
			P[i + 1] = 'C';
			return true;
		}
		else if(P[i] == 'S') f = true; 
	}
	return false;
}

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		scanf("%d %s", &D, P);

		len = strlen(P);
		int ans = 0;
		while(calc_socre() > D){
			if(drag_c()) ans++;
			else break;
		}

		if(calc_socre() <= D) printf("Case #%d: %d\n", tc, ans);
		else printf("Case #%d: IMPOSSIBLE\n", tc);
	}

	return 0;
}