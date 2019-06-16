#include <cstdio>

struct Node{
	bool act;
	Node *nxt[26];
};

int nidx = 1;
Node nodes[5000001];

void insert(char *s){
	Node *cur = &nodes[0];
	for(int i = 0; s[i]; i++){
		if(cur->nxt[s[i] - 'a'] == NULL){
			cur->nxt[s[i] - 'a'] = &nodes[nidx++];
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	cur->act = true;
}

bool find(char *s){
	Node *cur = &nodes[0];
	for(int i = 0; s[i]; i++){
		if(cur->nxt[s[i] - 'a'] == NULL)
			return false;
		cur = cur->nxt[s[i] - 'a'];
	}
	return cur->act;
}

char str[501];

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%s", str);
		insert(str);
	}

	int ans = 0;
	for(int i = 0; i < M; i++){
		scanf("%s", str);
		ans += find(str);
	}
	printf("%d\n", ans);

	return 0;
}