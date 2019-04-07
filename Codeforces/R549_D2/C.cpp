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

int N, par[100001];
bool y[100001], ok[100001];
vector<int> adj[100001], ans;

int main()
{
	scanf("%d", &N);
	for(int i = 1, p, c; i <= N; i++){
		scanf("%d %d", &p, &c);
		y[i] = (c == 1);
		adj[p].push_back(i);
		ok[p] |= !y[i];
		par[i] = p;
	}

	for(int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());

	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 1; i <= N; i++)
		if(y[i] && !ok[i]) q.push(i);

	if(q.empty()) return !printf("-1\n");
	while(!q.empty()){
		int cur = q.top(); q.pop();
		if(ok[cur]) continue;
		printf("%d ", cur);
	}
	printf("\n");

	return 0;
}
