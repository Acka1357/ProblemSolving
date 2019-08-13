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
using namespace std;

typedef long long ll;

struct Pizza{
	int idx, has, cost;
	bool operator <(const Pizza &o)const{
		return has == o.has ? cost < o.cost : has < o.has;
	}
};

Pizza p[100001];
int N, M, like[100001], happy[1 << 10];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		int cnt; scanf("%d", &cnt);
		for(int j = 0, x; j < cnt; j++){
			scanf("%d", &x);
			like[i] |= (1 << (x - 1));
		}
	}

	for(int i = 0; i < M; i++){
		scanf("%d", &p[i].cost);
		p[i].idx = i + 1;
		int cnt; scanf("%d", &cnt);
		for(int j = 0, x; j < cnt; j++){
			scanf("%d", &x);
			p[i].has |= (1 << (x - 1));
		}
	}

	sort(p, p + M);

	int P = 2;
	for(int i = 2; i < M; i++){
		if(p[i].has == p[P - 1].has && p[i].has == p[P - 2].has)
			continue;
		p[P++] = p[i];
	}

	for(int has = (1 << 10) - 1; has >= 0; has--){
		for(int i = 0; i < N; i++)
			if((has & like[i]) == like[i]) happy[has]++;
	}

	int ans_cnt = -1, ans_cost = 2000000000, ans1 = 0, ans2 = 0;
	for(int i = 0; i < P; i++)
		for(int j = i + 1; j < P; j++){
			int cnt = happy[p[i].has | p[j].has];
			int cost = p[i].cost + p[j].cost;
			if(ans_cnt < cnt || (ans_cnt == cnt && cost < ans_cost)){
				ans1 = p[i].idx; ans2 = p[j].idx;
				ans_cnt = cnt; ans_cost = cost;
			}
		}
	printf("%d %d\n", ans1, ans2);

	return 0;
}
