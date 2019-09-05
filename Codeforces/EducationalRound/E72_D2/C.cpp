#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[200005];
int d[200005];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int i = 1; i <= len; i++){
			if(s[i] == '0') d[i] = d[i - 1] + 1;
			else d[i] = 0;
		}

		int ans = 0, lb = (1 << 19) - 1;
		for(int r = 1, b = 0; r <= len; r++){
			b <<= 1; b |= (s[r] == '1');
			for(int len = 1, mod = 2; len <= 18; len++, mod <<= 1){
				if(r - len < 0) break;
				if(b % mod <= 0 || s[r - len + 1] == '0') continue;
				if(d[r - len] >= (b % mod) - len) ans++;
			}
			b &= lb;
		}
		printf("%d\n", ans);
	}
	return 0;
}