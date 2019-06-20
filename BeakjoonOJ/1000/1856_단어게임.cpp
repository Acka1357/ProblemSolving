#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, L, d[302], wl[600];
char s[302], w[600][26];

int main()
{
	int N, L; scanf("%d %d %s", &N, &L, s + 1);
	for(int i = 0; i < N; i++){
		scanf("%s", w[i]);
		wl[i] = strlen(w[i]);
	}

	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	for(int i = 1; i <= L; i++){
		d[i] = d[i - 1] + 1;
		for(int j = 0; j < N; j++){
			int cnt = 0, wi = wl[j] - 1;
			for(int k = i; k > 0 && wi >= 0; k--){
				if(w[j][wi] == s[k]){
					if(!(wi--)){
						d[i] = min(d[i], d[k - 1] + cnt);
						break;
					}
				}
				else cnt++;
			}
		}
	}
	printf("%d\n", d[L]);

	return 0;
}
