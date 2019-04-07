// solution:
// max가 낮은순 => min이 높은순 으로 정렬한 뒤
// 앞에서부터 가능한 가장 낮은 값의 로션을 배치하고
// 배치가능한 소의 수를 세는 것이 최적.
// 왜 골드 3번인지 모르겠는데 그 시절엔 지금만큼 티피컬하진 않았나봄.

// 시간복잡도: O(NlogN)
// 분류: Greedy
// 난이도: 1250

#include <cstdio>
#include <algorithm>
using namespace std;

struct Seg{
	int l, r;
	bool operator <(const Seg &o)const{
		return r == o.r ? l > o.l : r < o.r;
	}
};

Seg seg[2500];
int cap[1001];

int main()
{
	int C, L; scanf("%d %d", &C, &L);
	for(int i = 0; i < C; i++)
		scanf("%d %d", &seg[i].l, &seg[i].r);
	for(int i = 0, s, c; i < L; i++){
		scanf("%d %d", &s, &c);
		cap[s] += c;
	}

	sort(seg, seg + C);

	int ans = 0;
	for(int i = 0; i < C; i++){
		for(int j = seg[i].l; j <= seg[i].r; j++)
			if(cap[j]){
				cap[j]--; ans++; break;
			}
	}
	printf("%d\n", ans);

	return 0;
}