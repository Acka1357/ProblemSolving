#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <memory.h>
using namespace std;

struct Node{
	int cur, d;
	Node(){} Node(int cur, int d):cur(cur), d(d){}
};

int a[1000001], hs[1000001], past[1000001], maxd[1000001];
vector<int> h[1000001];
map<int, int> hidx;

int main()
{
	int N; scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		hs[i] = a[i];
	}

	sort(hs, hs + N);

	int H = 0;
	hidx[hs[0]] = H++;
	for(int i = 1; i < N; i++)
		if(hs[i] != hs[i - 1]) hidx[hs[i]] = H++;

	memset(past, 0xff, sizeof(past));

	int V = 1;
	h[a[0] = hidx[a[0]]].push_back(0);
	for(int i = 1; i < N; i++){
		a[V] = hidx[a[i]];
		if(a[V] != a[V - 1]){
			if(a[V] == a[V - 1] + 1) past[V] = V - 1;
			h[a[V]].push_back(V); V++;
		}
	}

	int pmax = 0, pcnt = 0, cmax = 0, ccnt = 0;
	for(int i = 1; i < H; i++){
		cmax = pmax; ccnt = 0;
		for(int j = 0; j < h[i].size(); j++){
			int &cur = h[i][j];
			if(past[cur] < 0) continue;
			maxd[cur] = pmax;
			if(past[cur] >= 0){
				if(pcnt != 1 || maxd[past[cur]] != pmax || h[i - 1].size() == 1){
					if(++maxd[cur] > cmax){
						ccnt = 0; cmax = maxd[cur];
					}
					if(maxd[cur] == cmax) ccnt++;
				}
			}
		}
		pmax = cmax; pcnt = ccnt;
	}

	printf("%d\n", V - 1 - pmax);
	return 0;
}
