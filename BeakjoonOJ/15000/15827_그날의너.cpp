#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;

struct Node{
	char name[21];
	ll uv, lv, xu, xl;
	char cmd;
	bool operator <(const Node &o)const{
		return strcmp(name, o.name) < 0;
	}
};

Node nodes[1001];
map<string, int> ni;
vector<int> bef[1001];
int nxt[1001], V = 0;
char s1[21], s2[21], s3[21], tmp;

int find_ni(char *name){
	string s(name);
	auto it = ni.find(s);
	if(it == ni.end()){
		strcpy(nodes[V].name, name);
		return ni[s] = V++;
	}
	return it->second;
}

void reduce(ll &u, ll &l){
	ll g = __gcd(abs(u), abs(l));
	u /= g, l /= g;
	if(l < 0) u *= -1, l *= -1;
}

void forward(int cur){
	for(int &b : bef[cur])
		forward(b);

	if(bef[cur].size() == 0) return ;

	ll au = nodes[bef[cur][0]].uv, al = nodes[bef[cur][0]].lv;
	ll bu = nodes[bef[cur][1]].uv, bl = nodes[bef[cur][1]].lv;
	ll &cu = nodes[cur].uv, &cl = nodes[cur].lv;
	if(nodes[cur].cmd == 'A'){
		cu = au * bl + bu * al;
		cl = al * bl;
	}
	else if(nodes[cur].cmd == 'S'){
		cu = au * bl - bu * al;
		cl = al * bl;
	}
	else if(nodes[cur].cmd == 'M'){
		cu = au * bu;
		cl = al * bl;
	}
	else if(nodes[cur].cmd == 'D'){
		cu = au * bl;
		cl = al * bu;
	}
	reduce(cu, cl);
}

void backprop(int cur, ll xu, ll xl){
	reduce(xu, xl);
	nodes[cur].xu = xu; nodes[cur].xl = xl;

	if(bef[cur].size() == 0) return ;

	ll au = nodes[bef[cur][0]].uv, al = nodes[bef[cur][0]].lv;
	ll bu = nodes[bef[cur][1]].uv, bl = nodes[bef[cur][1]].lv;

	if(nodes[cur].cmd == 'A'){
		backprop(bef[cur][0], xu, xl);
		backprop(bef[cur][1], xu, xl);
	}
	else if(nodes[cur].cmd == 'S'){
		backprop(bef[cur][0], xu, xl);
		backprop(bef[cur][1], -xu, xl);
	}
	else if(nodes[cur].cmd == 'M'){
		backprop(bef[cur][0], xu * bu, xl * bl);
		backprop(bef[cur][1], xu * au, xl * al);
	}
	else if(nodes[cur].cmd == 'D'){
		backprop(bef[cur][0], xu * bl, xl * bu);
		ll u[4] = {xu, au, bl, bl}, l[4] = {xl, al, bu, bu};
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				ll g = __gcd(abs(u[i]), abs(l[j]));
				u[i] /= g, l[j] /= g;
			}
		backprop(bef[cur][1], -u[0] * u[1] * u[2] * u[3], l[0] * l[1] * l[2] * l[3]);
	}
}

int main()
{
	int N; scanf("%d", &N);

	sprintf(s1, "HAPPY");
	find_ni(s1);
	nodes[0].xu = nodes[0].xl = 1;

	for(int i = 0; i < N; i++){
		scanf("%s %c", s1, &tmp);
		if(tmp == 'E'){
			ll x; scanf("%lld", &x);
			int ai = find_ni(s1);
			nodes[ai].uv = x;
			nodes[ai].lv = 1ll;
		}
		else{
			scanf(" %s %s", s2, s3);
			int ai = find_ni(s2), bi = find_ni(s3), ci = find_ni(s1);
			nodes[ci].cmd = tmp;
			bef[ci].push_back(ai);
			bef[ci].push_back(bi);
			nxt[ai] = nxt[bi] = ci;
		}
	}

	forward(0);
	backprop(0, 1ll, 1ll);

	sort(nodes, nodes + V);

	for(int i = 0; i < V; i++){
		printf("%s ", nodes[i].name);
		ll u = nodes[i].xu, l = nodes[i].xl;
		if(u == 0) printf("0/1\n");
		else printf("%lld/%lld\n", u, l);
	}
	return 0;
}