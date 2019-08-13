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
	int idx, l, r;
	bool operator <(const Node &o)const{
		return l < o.l;
	}
};

vector<Node> inc, dec;

void find_ans(vector<Node> &nodes, vector<int> &ans){
	if(nodes.empty()) return ;

	set<Node> nset;
	for(int i = 0 ; i < nodes.size(); i++)
		nset.insert(nodes[i]);

	auto it = nset.begin();
	int past = it->r;
	ans.push_back(it->idx);
	// printf("%d: (%d, %d)\n", it->idx, it->l, it->r);
	nset.erase(it);
	while(!nset.empty()){
		it = nset.lower_bound({-1, past, -1});
		if(it == nset.begin()) return ;
		it = prev(it);
		// printf("%d: (%d, %d)\n", it->idx, it->l, it->r);
		past = it->r;
		ans.push_back(it->idx);
		nset.erase(it);
	}
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1, l, r; i <= N; i++){
		scanf("%d %d", &l, &r);
		if(l < r) inc.push_back({i, l, r});
		else dec.push_back({i, r, l});
	}

	vector<int> ans_inc, ans_dec;
	find_ans(inc, ans_inc);
	find_ans(dec, ans_dec);

	if(ans_inc.size() < ans_dec.size()){
		printf("%d\n", ans_dec.size());
		for(int i = ans_dec.size() - 1; i >= 0; i--)
			printf("%d%c", ans_dec[i], " \n"[i == 0]);
	}
	else{
		printf("%d\n", ans_inc.size());
		for(int i = 0; i < ans_inc.size(); i++)
			printf("%d%c", ans_inc[i], " \n"[i == ans_inc.size() - 1]);
	}

	return 0;
}