#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Node{
	bool fin;
	char alp;
	vector<Node*> nxt;
};

Node nodes[1000001];
int nidx = 1, ans;
char str[81];

void add(char *s){
	Node *cur = &nodes[0];
	for(int i = 0; s[i]; i++){
		Node *nxt = NULL;
		for(Node *nxtn : cur->nxt)
			if(nxtn->alp == s[i]){
				nxt = nxtn; break;
			}
		if(nxt == NULL){
			memset(nodes + nidx, 0, sizeof(nodes[0]));
			nxt = &nodes[nidx++];
			nxt->alp = s[i];
			cur->nxt.push_back(nxt);
		}
		cur = nxt;
	}
	cur->fin = true;
}

void sum_len(Node *cur, int len){
	if(cur->fin) ans += len;
	if(cur != &nodes[0] && !cur->fin && cur->nxt.size() == 1)
		sum_len(cur->nxt[0], len);
	else{
		for(Node *nxtn : cur->nxt)
			sum_len(nxtn, len + 1);
	}
}

int main()
{	
	int N;
	while(scanf("%d", &N) == 1){
		memset(nodes, 0, sizeof(nodes[0]));
		for(int i = 0; i < N; i++){
			scanf("%s", str);
			add(str);
		}

		ans = 0;
		sum_len(&nodes[0], 0);
		printf("%.2lf\n", (double)ans / N);
	}
	return 0;
}
