#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Col{ 
	int amax;
	vector<int> a;
	bool operator <(const Col &o)const{
		return amax > o.amax;
	}
};

Col cols[101];
int R, C, org[4][100], tmp[4][4], ans;

void dfs(int idx, int tot){
	if(idx == tot){
		int sum = 0;
		for(int i = 0; i < R; i++){
			int imax = -1;
			for(int j = 0; j < tot; j++)
				imax = max(imax, tmp[i][j]);
			sum += imax;
		}
		ans = max(ans, sum);
		return ;
	}

	vector<int> &cur = cols[idx].a;
	for(int add = 0; add < R; add++){
		for(int i = 0; i < R; i++)
			tmp[i][idx] = cur[(i + add) % R];
		dfs(idx + 1, tot);
	}
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%d %d", &R, &C);

		for(int i = 0; i < C; i++){
			cols[i].a.clear();
			cols[i].amax = -1;
		}
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++){
				scanf("%d", &org[i][j]);
				cols[j].a.push_back(org[i][j]);
			}

		for(int i = 0; i < C; i++)
			for(int j = 0; j < R; j++)
				cols[i].amax = max(cols[i].amax, cols[i].a[j]);

		sort(cols, cols + C);

		ans = -1;
		dfs(0, min(R, C));
		printf("%d\n", ans);
	}
	return 0;
}
