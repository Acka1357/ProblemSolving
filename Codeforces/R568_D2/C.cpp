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

struct Node{ int sum, cnt; };
ll TN = 1 << 7;
Node tree[1 << 8];

int find(int sum, int idx = 1, int l = 1, int r = TN){
	if(l == r) return sum / l;
	if(tree[idx * 2].sum >= sum)
		return find(sum, idx * 2, l, (l + r) / 2);
	else return tree[idx * 2].cnt + find(sum - tree[idx * 2].sum, idx * 2 + 1, (l + r) / 2 + 1, r);
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);

	int sum = 0;
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x);
		sum += x;
		// printf("\n%d: %d\n", i, find(M - x));
		printf("%d%c", (sum > M ? i - find(M - x) : 0), " \n"[i == N - 1]);
		tree[TN + x - 1].sum += x;
		tree[TN + x - 1].cnt++;
		for(int idx = (TN + x - 1) / 2; idx; idx >>= 1)
			tree[idx] = {tree[idx * 2].sum + tree[idx * 2 + 1].sum,
						 tree[idx * 2].cnt + tree[idx * 2 + 1].cnt};
	}

	return 0;
}
