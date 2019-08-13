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

// struct Seg{
// 	int l, r;
// 	bool operator <(const Seg &o)const{
// 		return l == o.l ? r < o.r : l < o.l;
// 	}
// };

// int N, Q, d[2][3][5001], t;
// int N, Q, d[5001][5001][5001];
int N, Q, d[51][51][51];
vector<int> nxt[5001];

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 1, l, r; i <= Q; i++){
		scanf("%d %d", &l, &r);
		nxt[l].push_back(r);
	}

	// sort(seg + 1, seg + Q + 1);
	memset(d, 0xff, sizeof(d));

	int t = 0;
	d[0][0][0] = 0;
	// [t][hire][crd] = max
	for(int i = 1; i <= N; i++){
		sort(nxt[i].begin(), nxt[i].end());
		for(int r : nxt[i]){
			t++;
			for(int h = max(0, t - 2); h <= t; h++){
				for(int cur = i; cur <= r; cur++){
					if(d[t - 1][h][cur - 1] >= 0)
						d[t][h][cur] = max(d[t][h][cur], d[t - 1][h][cur - 1] + 1);
					if(h && d[t - 1][h - 1][cur] >= 0)
						d[t][h][cur] = max(d[t][h][cur], d[t - 1][h - 1][cur]);
				}
			}
		}
	}

	// memset(d, 0xff, sizeof(d[t]));

	// d[t][0][0] = 0;
	// for(int i = 1, last = 0; i <= Q; i++, t = !t){
	// 	memset(d[!t], 0xff, sizeof(d[!t]));

	// 	int l = seg[i].l, r = seg[i].r;
	// 	for(int j = 0; j < 3; j++)
	// 		for(int cur = l; cur <= r; cur++)
	// 			if(d[t][j][cur - 1] >= 0)
	// 				d[!t][j][cur] = max(d[!t][j][cur], d[t][j][cur - 1] + 1);

	// 	for(int j = 1; j < 3; j++){
	// 		if(d[t][j - 1][l - 1] >= 0)
	// 			d[!t][j][l] = max(d[!t][j][l], d[t][j - 1][l - 1]);
	// 		for(int cur = l + 1; cur <= r; cur++)
	// 			if(d[t][j][cur - 1] >= 0) 
	// 				d[!t][j][cur] = max(d[!t][j][cur], d[t][j][cur - 1]);
	// 	}
	// 	last = max(last, r);
	// }

	printf("%d\n", N - d[t][t - 2][N]);
	return 0;
}
