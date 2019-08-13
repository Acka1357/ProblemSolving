#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

char s[101], t[101], p[101];

int main()
{
	int T; for(scanf("%d", &T); T--;){
		scanf("%s %s %s", s, t, p);

		int rem[26] = {0,};
		for(int i = 0; p[i]; i++)
			rem[p[i] - 'a']++;

		int si = 0, ti = 0;
		bool psb = true;
		while(t[ti] && psb){
			if(s[si] && s[si] == t[ti]) si++, ti++;
			else{
				if(--rem[t[ti] - 'a'] < 0) psb = false;
				ti++;
			}
		}
		if(s[si]) psb = false;
		printf("%s\n", psb ? "YES" : "NO");
	}
	return 0;
}
