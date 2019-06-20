#include <stdio.h>
#include <string>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
using namespace std;

struct Query{
	string s; int ni, qi;
	bool operator <(const Query &o)const{
		return ni < o.ni;
	}
};

struct Node{ 
	int cnt, alp; bool ex; vector<Node*> nxt; 
	Node(){} Node(int alp): alp(alp), cnt(0), ex(false){}
};

string dic[30001];
char tmp[31];
Query q[30001];
map<string, int> dic_map;
int N, Q, ans[30001], rev[30001];
Node root;

void add_s(string &s){
	int curi = 0;
	Node *cur = &root, *nxt;;
	for(int i = 0; i < s.size(); i++){
		cur->cnt++; nxt = 0;
		for(int j = 0; j < cur->nxt.size(); j++)
			if(cur->nxt[j]->alp == s[i]) nxt = cur->nxt[j];
		if(!nxt){
			nxt = new Node(s[i]);
			cur->nxt.push_back(nxt);
		}
		cur = nxt;
	}
	cur->cnt++;
	cur->ex = true;
}

int search_s(string &s){
	int sum = 0, curi = 0;
	Node *cur = &root, *nxt;
	for(int i = 0; i < s.size(); i++){
		sum += cur->cnt; nxt = 0;
		for(int j = 0; j < cur->nxt.size(); j++)
			if(cur->nxt[j]->alp == s[i]) nxt = cur->nxt[j];
		if(!nxt) return sum;
		cur = nxt;
	}
	return sum + cur->cnt;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", tmp);
		dic[i] = tmp;
		for(char &c : dic[i]) c -= 'a';
		dic_map[dic[i]] = i;
	}

	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%s", tmp);
		q[i].s = tmp; q[i].qi = i;
		for(char &c : q[i].s) c -= 'a';
		auto it = dic_map.lower_bound(q[i].s);
		if(it == dic_map.end() || q[i].s != it->first) q[i].ni = N;
		else q[i].ni = it->second;
	}
	sort(q, q + Q);

	int ni = 0;
	for(int i = 0; i < Q; i++){
		while(ni <= q[i].ni && ni < N) add_s(dic[ni++]);
		ans[q[i].qi] = search_s(q[i].s);
	}

	for(int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);

	return 0;
}
