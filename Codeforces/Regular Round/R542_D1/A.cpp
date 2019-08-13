#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ull INF = 0x3f3f3f3f3f3f3f3f;

ull N, M, need[5001];
vector<int> c[5001];

int main()
{
	scanf("%llu %llu", &N, &M);
	for(int i = 0, s, e; i < M; i++){
		scanf("%d %d", &s, &e);
		c[s].push_back(e);
	}

	for(int i = 1; i <= N; i++){
		if(c[i].size()) need[i] = INF;
		for(int x : c[i]){
			if(x < i) need[i] = min(need[i], N * c[i].size() - (i - x));
			else need[i] = min(need[i], N * (c[i].size() - 1) + x - i);
		}
		// printf("%d:%llu ", i, need[i]);
	}

	for(int i = 1; i <= N; i++){
		ull ans = 0;
		for(int j = 1; j <= N; j++)
			if(need[j])
				ans = max(ans, need[j] + (j < i ? N - i + j : j - i));
		printf("%llu%c", ans, " \n"[i == N]);
	}

	return 0;
}
