#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Seg{ 
	int s, e, c; 
	bool operator <(const Seg &o)const{
		return s < o.s;
	}
};

int d[1000002];
Seg seg[1000];

int main()
{
	int N, M, R; scanf("%d %d %d", &N, &M, &R);
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &seg[i].s, &seg[i].e, &seg[i].c);
		seg[i].e = min(seg[i].e + R, N);
	}
	
	sort(seg, seg + M);

	for(int i = 0, si = 0; i <= N; i++){
		if(i) d[i] = max(d[i], d[i - 1]);
		while(si < M && seg[si].s == i){
			d[seg[si].e] = max(d[seg[si].e], d[i] + seg[si].c);
			si++;
		}
	}
	printf("%d\n", d[N]);

	return 0;
}