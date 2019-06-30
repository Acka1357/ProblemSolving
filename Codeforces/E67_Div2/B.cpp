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

vector<int> idx[256];
char s[200001], t[200001];

int main()
{
	int L, N; scanf("%d %s %d", &L, s, &N);
	for(int i = 0; i < L; i++)
		idx[s[i]].push_back(i + 1);

	while(N--){
		scanf("%s", t);
		int cnt[256] = {0,};
		for(int i = 0; t[i]; i++)
			cnt[t[i]]++;
		int ans = 0;
		for(int i = 'a'; i <= 'z'; i++)
			if(cnt[i]) ans = max(ans, idx[i][cnt[i] - 1]);
		printf("%d\n", ans);
	}
	return 0;
}
