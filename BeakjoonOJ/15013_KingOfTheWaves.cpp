#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

bool win[1000][1000], chk[1000];
vector<int> adj[1000], ans;

void dfs(int cur){
	chk[cur] = true;
	stack<int> st;
	for(int i = 0; i < adj[cur].size(); i++){
		if(chk[adj[cur][i]]) continue;
		dfs(adj[cur][i]);
		st.push(adj[cur][i]);
	}

	for(; !st.empty(); st.pop())
		ans.push_back(st.top());
}

char s[1001];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", s);
		for(int j = 0; j < N; j++)
			if(s[j] == '1') adj[i].push_back(j);
	}

	dfs(0);
	
	for(int i = 0; i < N; i++)
		if(!chk[i]) return !printf("impossible\n");

	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("0\n");

	return 0;
}
