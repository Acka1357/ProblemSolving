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

int a[300000], b[300000];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int L; scanf("%d", &L);
		for(int i = 0; i < L; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < L; i++)
			scanf("%d", &b[i]);

		int diff = 0, l = 0;
		map<int, int> acnt, bcnt;
		for(int i = 0; i < L; i++){
			if(diff == 0) l = i;
			if(a[i] == b[i]){
				acnt[a[i]]++; bcnt[b[i]]++;
				continue;
			}
			else{
				int ab = (acnt.count(b[i]) ? acnt[b[i]] : 0);
				int ba = (bcnt.count(a[i]) ? bcnt[a[i]] : 0);
				int aa = ++acnt[a[i]];
				int bb = ++bcnt[b[i]];
				// printf("%d: %d %d %d %d\n", i, ab, ba, aa, bb);
				if(aa == ba) diff--;
				else if(aa == ba + 1) diff++;
				if(bb == ab) diff--;
				else if(bb == ab + 1) diff++;
			}
			if(diff == 0) sort(a + l, a + i + 1);
		}

		bool psb = true;
		for(int i = 0; i < L; i++)
			if(a[i] != b[i]){
				psb = false; break;
			}
		printf("%s\n", psb ? "YES" : "NO");
	}
	return 0;
}
