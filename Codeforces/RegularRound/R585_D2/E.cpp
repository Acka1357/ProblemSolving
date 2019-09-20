#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int a[400005], bit[21];
ll d[1 << 20], cost[21][21];
vector<int> idx[21];

int main()
{
	for(int i = 1; i <= 20; i++)
		bit[i] = 1 << (i - 1);

	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		idx[a[i]].push_back(i);
	}

	for(int i = 1; i <= 20; i++)
		sort(idx[i].begin(), idx[i].end());

	for(int a = 1; a <= 20; a++)
		for(int b = 1; b <= 20; b++){
			if(a == b) continue;
			for(int i = 0, bi = 0; i < idx[a].size(); i++){
				while(bi < idx[b].size() && idx[a][i] > idx[b][bi]) bi++;
				cost[a][b] += bi;
			}
		}

	memset(d, 0x3f, sizeof(d));
	int all = (1 << 20) - 1;
	d[0] = 0;
	for(int st = 0; st < all; st++){
		for(int cur = 1; cur <= 20; cur++){
			if(st & bit[cur]) continue;
			ll sum = d[st];
			for(int past = 1; past <= 20; past++)
				if(st & bit[past]) sum += cost[past][cur];
			d[st | bit[cur]] = min(d[st | bit[cur]], sum);
		}
	}
	printf("%lld\n", d[all]);

	return 0;
}