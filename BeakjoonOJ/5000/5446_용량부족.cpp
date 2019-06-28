#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Node{
	char alp; bool del; int cnt;
	vector<Node*> nxt;
};

char str[21];
Node nodes[40001], *nst[21];
int nidx = 1;

void add(char *s, bool del){
	Node *cur = &nodes[0];
	int len = 0; nst[0] = &nodes[0];
	for(; s[len]; len++){
		Node *nxt = NULL;
		for(Node *nxtn : cur->nxt)
			if(nxtn->alp == s[len]){
				nxt = nxtn; break;
			}
		if(nxt == NULL){
			memset(nodes + nidx, 0, sizeof(nodes[0]));
			nxt = &nodes[nidx++];
			nxt->alp = s[len];
			cur->nxt.push_back(nxt);
		}
		cur = nxt;
		if(del) cur->cnt = 1;
		nst[len + 1] = cur;
	}

	if(del){
		cur->del = true;
		return ;
	}

	for(int i = len; i >= 0; i--){
		cur = nst[i];
		cur->cnt = cur->del;
		for(int j = 0; j < cur->nxt.size(); j++)
			cur->cnt += cur->nxt[j]->cnt;
	}
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		memset(nodes, 0, sizeof(nodes[0]));
		nidx = 1;
		nodes[0].del = false;
		nodes[0].cnt = 1;

		int N; scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%s", str);
			add(str, true);
		}

		int M; scanf("%d", &M);
		for(int i = 0; i < M; i++){
			scanf("%s", str);
			add(str, false);
		}
		printf("%d\n", nodes[0].cnt);
	}
	return 0;
}