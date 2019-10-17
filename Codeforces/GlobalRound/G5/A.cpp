#include <cstdio>

int a[15000], psum, nsum, pcnt, ncnt;

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		if(a[i] >= 0) psum += a[i] / 2;
		else nsum -= a[i] / 2;
	}

	for(int i = 0; i < N; i++){
		if(a[i] >= 0){
			if(psum < nsum) printf("%d\n", (a[i] + 1) / 2), psum += (a[i] & 1);
			else if(psum > nsum) printf("%d\n", (a[i] + 2) / 2 - 1);
			else printf("%d\n", a[i] / 2);
		}
		else{
			if(nsum < psum) printf("%d\n", (a[i] - 1) / 2), nsum += (-a[i] & 1);
			else if(nsum > psum) printf("%d\n", a[i] / 2);
			else printf("%d\n", a[i] / 2);
		}
	}

	return 0;
}