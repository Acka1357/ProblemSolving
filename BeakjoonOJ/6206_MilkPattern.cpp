#include <cstdio>
#include <unordered_map>
using namespace std;

typedef unsigned long long ull;

const ull B = 1000003;
int N, K, a[20000];

bool chk_l(int l){
	unordered_map<ull, int> cnt;
	ull hash = 0, tm = 1;
	for(int i = 0; i < l; i++, tm *= B)
		hash = (hash * B) + a[i];
	cnt[hash]++;
	for(int i = l; i < N; i++){
		hash = hash * B + a[i] - a[i - l] * tm;
		if(++cnt[hash] >= K) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int l = 1, r = N, m, ans = 0;
	while(l <= r){
		m = (l + r) / 2;
		if(chk_l(m)) l = m + 1, ans = m;
		else r = m - 1;
	}
	printf("%d\n", ans);

	return 0;
}
