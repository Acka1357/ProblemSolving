#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <utility>
#include <assert.h>
using namespace std;

struct Node{
	int idx, d;
	bool operator <(const Node &o)const{
		return d < o.d;
	}
};

Node a[501];
int N, dsum, ocnt, orgd[501];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i].d);
		a[i].idx = i + 1;
		dsum += a[i].d;
		if(a[i].d == 1) ocnt++;
	}
	if(dsum < 2 * N - 2) return !printf("NO\n");

	sort(a, a + N);
	for(int i = 0; i < N; i++)
		orgd[i] = a[i].d;

	printf("YES %d\n", N - max(2, ocnt) + 1);
	printf("%d\n", N - 1);
	for(int i = 1, r = N - 1; i < N; i++){
		if(orgd[i] == 1){
			while((r == N - 1 && a[r].d <= 1) || (r < N - 1 && a[r].d <= 2)) r--;
			printf("%d %d\n", a[i].idx, a[r].idx);
			a[i].d--;
			a[r].d--;
		}
		else{
			printf("%d %d\n", a[0].idx, a[i].idx);
			a[i].d--;
			assert(a[0].d >= 0);
			assert(a[i].d >= 0);
			for(int j = i + 1; j < N; j++){
				printf("%d %d\n", a[j - 1].idx, a[j].idx);
				a[j - 1].d--;
				a[j].d--;
				assert(a[j - 1].d >= 0);
				assert(a[j].d >= 0);
			}
			break;
		}
	}

	return 0;
}
