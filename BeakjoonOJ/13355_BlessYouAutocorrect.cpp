#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

struct Node{
	char ai[26];
	bool ex;
	int mind;
	vector<Node*> next;
	Node(){ memset(ai, 0xff, sizeof(ai)); }
};

char str[1000001];
Node nodes[1000002];
int ncnt = 0, alp;

void add_node(char *s){
	Node *cur = &nodes[0];
	for(int i = 0; s[i]; i++){
		alp = s[i] - 'a';
		if(cur->ai[alp] < 0){
			cur->ai[alp] = cur->next.size();
			cur->next.push_back(&nodes[++ncnt]);
			if(!s[i + 1]) nodes[ncnt].ex = true;
		}
		cur = cur->next[cur->ai[alp]];
	}
}

int set_mind(Node *cur, int len, int tab){
	cur->mind = len;
	if(cur->ex) cur->mind = min(cur->mind, tab + 2);
	if(cur->next.size())
		cur->mind = min(cur->mind, 
						set_mind(cur->next[0], cur->mind + 1, cur->ex ? cur->mind : tab) + 1);
	for(int i = 1; i < cur->next.size(); i++)
		set_mind(cur->next[i], cur->mind + 1, cur->mind);
	return cur->mind;
}

int find_ans(char *s){
	Node *cur = &nodes[0];
	for(int i = 0; s[i]; i++){
		alp = s[i] - 'a';
		if(cur->ai[alp] < 0) return cur->mind + strlen(s) - i;
		cur = cur->next[cur->ai[alp]];
	}
	return cur->mind;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%s", str);
		add_node(str);
	}

	set_mind(&nodes[0], 0, 0);

	while(M--){
		scanf("%s", str);
		printf("%d\n", find_ans(str));
	}

	return 0;
}
