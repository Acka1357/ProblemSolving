#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> cow[1000001];
int d[1000001], mi[25001];

int main()
{
	int N, T; scanf("%d %d", &N, &T);
	for(int i = 0, l, r; i < N; i++){
		scanf("%d %d", &l, &r);
		cow[l].push_back(r);
	}

	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	for(int i = 1, last = 0, val = 0; i <= T; i++){
		d[i] = (val += (i > mi[val]));
		for(int j = 0; j < cow[i].size(); j++){
			d[cow[i][j]] = min(d[cow[i][j]], d[i - 1] + 1);
			mi[d[cow[i][j]]] = max(mi[d[cow[i][j]]], cow[i][j]);
			last = max(last, cow[i][j]);
		}
		if(last < i) return !printf("-1\n");
	}
	printf("%d\n", d[T]);

	return 0;
}
