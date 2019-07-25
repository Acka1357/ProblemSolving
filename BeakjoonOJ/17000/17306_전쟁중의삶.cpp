/*
	2019 경인지역 6개대학 연합 프로그래밍 경시대회 shake!
	Acka's cpp solution - wartime
	Time Complexity: O(N * logA * log(N * logA))
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int NAIVE_MAX = 9000000;

bool chk[NAIVE_MAX + 1];
ll inp[250000];
vector<ll> node;
vector<int> cnt;

int find_idx(ll x){
	int l = 0, r = node.size(), m;
	while(l <= r){
		m = (l + r) / 2;
		if(node[m] < x) l = m + 1;
		else if(node[m] > x) r = m - 1;
		else return m;
	}
	return -1;
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &inp[i]);
		for(ll x = inp[i]; x; x >>= 1){
			if(x > NAIVE_MAX) node.push_back(x);
			else if(!chk[x]){
				node.push_back(x);
				chk[x] = true;
			}
		}
	}

	sort(node.begin(), node.end());
	node.erase(unique(node.begin(), node.end()), node.end());
	cnt = vector<int>(node.size(), 0);

	for(int i = 0; i < N; i++)
		cnt[find_idx(inp[i])] = 1;

	int ans = 0;
	for(int i = node.size() - 1; i >= 0; i--){
		ans++;
		if(cnt[i] == N) break;
		cnt[find_idx(node[i] / 2)] += cnt[i];
	}	
	printf("%d\n", ans);

	return 0;
}
