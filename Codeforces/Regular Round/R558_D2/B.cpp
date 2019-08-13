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
using namespace std;

set<int> cc[100002];
int cnt[100002];

int main()
{
	int N; scanf("%d", &N);
	
	int ans = 0, minc1 = 0, minc2 = 0, maxc1 = 0, maxc2 = 0;
	for(int i = 1, u; i <= N; i++){
		scanf("%d", &u);

		if(cnt[u]) cc[cnt[u]].erase(cc[cnt[u]].find(u));
		else { minc2 = minc1; minc1 = 0; }
		
		cc[++cnt[u]].insert(u);
		while(!cc[minc1].size()) minc1++;
		
		minc2 = max(minc1, minc2);
		if(minc1 == minc2){
			if(cc[minc2].size() == 1) minc2++;
		}
		while(!cc[minc2].size()) minc2++;
		
		if(cnt[u] - 1 == maxc1){
			if(cc[maxc1].size() > 0) maxc2 = maxc1++;
			else maxc1++;
		}
		else{
			while(!cc[maxc2].size()) maxc2++;
		}

		// printf("%d: %d %d %d %d\n", i, minc1, minc2, maxc1, maxc2);

		if((minc1 == maxc1 && (minc1 != minc2 || maxc1 != maxc2))
			|| (minc1 == maxc2 && maxc2 == maxc1 - 1 && cc[maxc1].size() == 1)
			|| (minc2 == maxc1 && minc1 == 1))
			ans = i;
	}
	printf("%d\n", ans);
	return 0;
}
