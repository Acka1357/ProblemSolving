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

bool chk[200001];
int a[200001];

int main()
{
	int N, Z; scanf("%d %d", &N, &Z);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a, a + N);

	int ans = 0, r = N / 2;
	for(int i = 0; i < N; i++)
		if(!chk[i]){
			while(r < N && a[r] - a[i] < Z) r++;
			if(r >= N) break;
			chk[i] = chk[r++] = true;
			ans ++;
		} 
	printf("%d\n", ans);

	return 0;
}
