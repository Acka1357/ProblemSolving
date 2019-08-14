#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

char s[100005];
int scr[256];
ll cum[256];
map<pair<ll, char>, int> cnt;

int main()
{
	for(int i = 'a'; i <= 'z'; i++)
		scanf("%d", &scr[i]);
	scanf("%s", s);

	ll cur = 0, ans = 0, org;
	for(int i = 0; s[i]; i++){
		if(i) ans += cnt[{cur - scr[s[i]], s[i]}];
		cnt[{cur, s[i]}]++;
		cur += scr[s[i]];
	}
	printf("%lld\n", ans);

	return 0;
}