#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Crd{ 
	int y, z, idx;
	bool operator <(const Crd &o) const{ 
		return y == o.y ? z < o.z : y < o.y; 
	}
};

struct Crd2{
	int z, idx;
	bool operator <(const Crd2 &o)const{
		return z < o.z;
	}
};

int x[50004], y[50004], z[50004], li[50004], ri[50004];
vector<int> xs;
vector<Crd> bucket[50004];
map<int, int> xidx;
queue<int> q;

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		xs.push_back(x[i]);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for(int i = 0; i < (int)xs.size(); i++)
		xidx[xs[i]] = i;

	for(int i = 0; i < N; i++){
		int xx = xidx[x[i]];
		bucket[xx].push_back({y[i], z[i], i + 1});
	}

	for(int x = 0; x < (int)xs.size(); x++){
		vector<int> ys;
		map<int, int> yidx;
		for(Crd &c : bucket[x])
			ys.push_back(c.y);

		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		for(int i = 0; i < (int)ys.size(); i++)
			yidx[ys[i]] = i;

		vector<vector<Crd2>> zs(ys.size(), vector<Crd2>());
		for(Crd &c : bucket[x])
			zs[yidx[c.y]].push_back({c.z, c.idx});

		for(int y = 0; y < (int)ys.size(); y++){
			li[y] = 0, ri[y] = (int)zs[y].size() - 1;
			sort(zs[y].begin(), zs[y].end());
		}

		queue<int> q2;
		for(int y = 0; y < (int)ys.size(); y++){
			while(ri[y] > li[y]){
				printf("%d %d\n", zs[y][li[y]].idx, zs[y][li[y] + 1].idx);
				li[y] += 2;
			}
			if(li[y] == ri[y]) q2.push(zs[y][li[y]].idx);
		}

		while(q2.size() >= 2){
			printf("%d ", q2.front()); q2.pop();
			printf("%d\n", q2.front()); q2.pop();			
		}
		if(!q2.empty()){
			q.push(q2.front()); q2.pop();
		}
	}

	while(!q.empty()){
		printf("%d ", q.front()); q.pop();
		printf("%d\n", q.front()); q.pop();
	}

	return 0;
}