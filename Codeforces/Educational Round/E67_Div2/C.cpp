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

struct Q{ 
	int t, l, r;
	bool operator <(const Q &o)const{
		return t == o.t ? (l == o.l ? r > o.r : l < o.l) : t > o.t;
	}
};

Q q[1000];
int ans[1000];

int main()
{
	int L, N; scanf("%d %d", &L, &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &q[i].t, &q[i].l, &q[i].r);
		q[i].l--; q[i].r--;
	}

	sort(q, q + N);

	int cur = 0, pl = 0, nr = -1, num = 0, idx;
	for(idx = 0; idx < N; idx++){
		if(q[idx].t == 0) break;
		if(q[idx].l > nr) cur = q[idx].l, num = 10000;
		nr = max(nr, q[idx].r);
		while(cur <= nr) ans[cur++] = num++;
	}

	if(!ans[0]) ans[0] = 1000000000;
	for(; idx < N; idx++){
		int emptyi = -1;
		for(int i = q[idx].l + 1; i <= q[idx].r; i++){
			if(ans[i] && ans[i - 1] && ans[i - 1] > ans[i]){
				emptyi = -2; break;
			}
			if(!ans[i]){
				emptyi = i; break;
			}
		}
		if(emptyi == -2) continue;
		else if(emptyi == -1) return !printf("NO\n");
		else{
			if(!ans[emptyi - 1]) ans[emptyi - 1] = 5000;
			ans[emptyi] = ans[emptyi - 1] - 1;
		}
	}

	printf("YES\n");
	for(int i = 0; i < L; i++){
		if(!ans[i]) ans[i] = 1;
		printf("%d%c", ans[i], " \n"[i == L - 1]);
	}

	return 0;
}
