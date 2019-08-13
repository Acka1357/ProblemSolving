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
#include <set>
#include <map>
using namespace std;

typedef long long ll;

struct Node{
	int v, idx;
	bool operator <(const Node &o)const{
		return v < o.v;
	}
}

Node nodes[300001];
int N, res[300001];
ll nsum, rsum;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &nodes[i].v);
		nsum += nodes[i].v;
		nodes[i].idx = i + 1;
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &res[i]);
		rsum += res[i];
	}

	sort(nodes + 1, nodes + N + 1);
	sort(res + 1, res + N + 1);

	if(nsum != rsum || res[1] < nodes[1]. v || nodes[N] < res[N])
		return !printf("NO\n");

	for(int i = 1, nxt = N; i <= N; i++){
		if(res[])
	}

	return 0;
}
