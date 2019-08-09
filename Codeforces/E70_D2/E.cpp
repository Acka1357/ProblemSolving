#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

struct Node{
	int idx, cnt;
	Node *nxt[26], *fail;
};

int nidx = 2, L;
Node nodes[400002];
ll st[200001], ed[200001];

void add(char *s, Node *cur, int si, int di){
	for(int i = 0, val; s[i]; i++, si += di){
		val = s[i] - 'a';
		if(!(cur->nxt[val])){
			nodes[nidx].idx = si;
			cur->nxt[val] = &nodes[nidx++];
		}
		cur = cur->nxt[val];
	}
	cur->cnt++;
}

void set_fail(Node *head){
	head->fail = head;
	queue<Node*> q;
	q.push(head);
	while(!q.empty()){
		Node *cur = q.front(); q.pop();
		for(int i = 0; i < 26; i++){
			Node *nxt = cur->nxt[i], *fail = cur->fail;
			if(!nxt) continue;
			while(fail != head && fail->nxt[i] == NULL)
				fail = fail->fail;
			if(cur != head && fail->nxt[i])
				nxt->fail = fail->nxt[i];
			else nxt->fail = head;
			nxt->cnt += nxt->fail->cnt;
			q.push(nxt);
		}
	}
}

char t[200001], str[200001];

int main()
{
	int N; scanf("%s %d", t, &N);
	L = strlen(t);
	for(int i = 0; i < N; i++){
		scanf("%s", str);
		add(str, &nodes[0], 0, 1);
		int len = strlen(str);
		for(int j = (len - 1) / 2; j >= 0; j--)
			swap(str[j], str[len - j - 1]);
		add(str, &nodes[1], len - 1, -1);
	}

	set_fail(&nodes[0]);
	set_fail(&nodes[1]);

	Node *cur = &nodes[0];
	for(int i = 0; i < L; i++){
		int nval = t[i] - 'a';
		while(cur != &nodes[0] && cur->nxt[nval] == NULL)
			cur = cur->fail;
		if(cur->nxt[nval]) cur = cur->nxt[nval];
		ed[i] += cur->cnt;
	}

	cur = &nodes[1];
	for(int i = L - 1; i >= 0; i--){
		int nval = t[i] - 'a';
		while(cur != &nodes[1] && cur->nxt[nval] == NULL)
			cur = cur->fail;
		if(cur->nxt[nval]) cur = cur->nxt[nval];
		st[i] += cur->cnt;		
	}

	ll ans = 0;
	for(int i = 1; i < L; i++)
		ans += ed[i - 1] * st[i];
	printf("%lld\n", ans);

	return 0;
}
