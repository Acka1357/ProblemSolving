#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

char s[200005], tmp[200005], ans[200005];
char a[200005], b[200005];

bool order(char *x, int l, int r){
	for(int i = l + 1; i <= r; i++)
		if(x[i - 1] > x[i]) return false;
	return true;
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int L; scanf("%d %s", &L, s + 1);
		memcpy(tmp + 1, s + 1, L);
		int ai = 0, bi = 0;
		sort(tmp + 1, tmp + L + 1);
		for(int i = 1; i <= L; i++){
			if(s[i] == tmp[ai + 1]) a[++ai] = s[i], ans[i] = '1';
			else if(bi && s[i] < b[bi]) a[++ai] = s[i], ans[i] = '1';
			else b[++bi] = s[i], ans[i] = '2';
		}

		ans[L + 1] = 0;
		if(ai && bi) printf("%s\n", (a[ai] <= b[1] && order(a, 1, ai) && order(b, 1, bi)) ? ans + 1 : "-");
		else if(ai) printf("%s\n", order(a, 1, ai) ? ans + 1 : "-");
		else if(bi) printf("%s\n", order(b, 1, bi) ? ans + 1 : "-");
		else while(true);
	}
	return 0;
}
