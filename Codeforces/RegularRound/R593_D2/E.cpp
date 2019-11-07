#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int BASE = 100001;
int B, N, a[100005], samer[100005], top[100005], btm[100005], d1[100005], d2[100005];
vector<vector<int>> inc, dec;

int find_top(int S, vector<vector<int>> &bucket, int *top, int *d){
	int cur = S, idx = 0;
	while(idx <= N){
		vector<int> &v = bucket[cur - idx + BASE];
		auto it = upper_bound(v.begin(), v.end(), idx);
		if(it == v.end()) return cur + N - idx + 1;
		if(d[samer[*it]]) return top[d[samer[*it]]];
		d[samer[*it]] = S;
		cur = a[*it];
		idx = samer[*it] + 1;
	}
	return cur;
}

int find_btm(int S, vector<vector<int>> &bucket, int *btm, int *d){
	int cur = S, idx = 0;
	while(idx <= N){
		vector<int> &v = bucket[cur - (N - idx + 1) + BASE];
		auto it = upper_bound(v.begin(), v.end(), idx);
		if(it == v.end()) return cur - (N - idx) - 1;
		if(d[samer[*it]]) return btm[d[samer[*it]]];
		d[samer[*it]] = S;
		cur = a[*it];
		idx = samer[*it] + 1;
	}
	return cur;
}

int main()
{
	inc = vector<vector<int>>(2 * BASE + 1, vector<int>());
	dec = vector<vector<int>>(2 * BASE + 1, vector<int>());

	scanf("%d %d", &B, &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	for(int i = 1; i <= N; i++){
		int r = i;
		while(a[i] == a[r + 1]) r++;
		for(int j = i; j <= r; j++)
			samer[j] = r;
		i = r;
	}
	if(B == 1 && a[1] == 1 && samer[1] == N)
		return !printf("0\n");

	for(int i = 1; i <= N; i++)
		inc[a[i] - i + BASE].push_back(i);
	for(int i = 1; i <= N; i++)
		dec[a[i] - (N - i + 1) + BASE].push_back(i);

	ll ans = 0;
	for(int i = 1; i <= B; i++){
		top[i] = min(B, find_top(i, inc, top, d1));
		btm[i] = max(1, find_btm(i, dec, btm, d2));
		// printf("%d: [%d, %d]\n", i, btm[i], top[i]);
		ans += top[i] - btm[i] + 1;
	}
	printf("%lld\n", ans);

	return 0;
}