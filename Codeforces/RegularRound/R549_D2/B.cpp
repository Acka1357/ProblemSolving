#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

char s[11];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	ll ans = 1;
	for(int i = 0; i < len; i++)
		ans *= s[i] - '0';
	for(int i = len - 1; i >= 0; i--){
		s[i] = '9';
		if(--s[i - 1] < '0') continue;
		ll tmp = 1;
		for(int j = 0; j < len; j++)
			tmp *= s[j] - '0';
		ans = max(ans, tmp);
	}
	ll tmp = 1;
	int idx = 0;
	while(s[idx] == '0') idx++;
	for(int i = max(1, idx); i < len; i++)
		tmp *= s[i] - '0';

	printf("%lld\n", max(ans, tmp));

	return 0;
}
