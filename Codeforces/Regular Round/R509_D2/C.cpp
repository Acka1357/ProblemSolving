#include <stdio.h>
#include <algorithm>
using namespace std;

struct Info{
	int a, idx;
	bool operator <(const Info &o)const{
		return a < o.a;
	}
};

Info info[200000];
int d[200000];
bool chk[200000];

int main()
{
	int N, M, D; scanf("%d %d %d", &N, &M, &D);
	for(int i = 0; i < N; i++){
		scanf("%d", &info[i].a);
		info[i].idx = i;
	}

	sort(info, info + N);

	int ans = 0, curl = 0;
	for(int i = 0; i < N; i++){
		if(!chk[i]) d[info[i].idx] = ++ans;
		int l = curl + 1, r = N - 1, m;
		while(l <= r){
			m = (l + r) / 2;
			if(info[m].a > info[i].a + D){
				curl = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		if(chk[curl]) continue;
		chk[curl] = true;
		d[info[curl].idx] = d[info[i].idx];
	}

	printf("%d\n", ans);
	for(int i = 0; i < N; i++)
		printf("%d ", d[i]);
	printf("\n");

	return 0;
}