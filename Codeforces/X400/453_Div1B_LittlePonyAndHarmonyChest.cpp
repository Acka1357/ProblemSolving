#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;

vector<int> pri, psb[1 << 17];
int N, a[101], b[101], d[101][1 << 17], bit[60], c[101][1 << 17];

int main()
{
	for(int i = 2, b = 1; i < 60; i++){
		bool p = true;
		for(int j = 2; j < i; j++)
			if(!(i % j)){
				p = false;
				bit[i] |= bit[j];
			}
		if(p){
			pri.push_back(i);
			bit[i] |= b; b <<= 1;
		}
	}

	for(int i = (1 << 17) - 1; i >= 0; i--)
		for(int j = 1; j < 60; j++)
			if(!(i & bit[j])) psb[i].push_back(j);

	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	memset(d, 0x3f, sizeof(d));
	d[0][0] = 0;
	for(int i = 1; i <= N; i++)
		for(int st = (1 << 17) - 1; st >= 0; st--)
			for(int n : psb[st]){
				if(n >= a[i] * 2) break;
				int cost = d[i - 1][st] + abs(a[i] - n);
				int nst = st | bit[n];
				if(cost < d[i][nst]){
					d[i][nst] = cost;
					c[i][nst] = n;
				}
			}

	int ans = inf, pst = -1;
	for(int i = (1 << 17) - 1; i >= 0; i--)
		if(d[N][i] < ans) ans = d[N][i], pst = i;

	for(int i = N; i > 0; i--){
		b[i] = c[i][pst];
		pst ^= bit[b[i]];
	}

	for(int i = 1; i <= N; i++)
		printf("%d%c", b[i], " \n"[i == N]);

	return 0;
}