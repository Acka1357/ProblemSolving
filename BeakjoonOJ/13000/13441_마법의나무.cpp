#include <stdio.h>
#include <vector>
using namespace std;

struct BTM{
	int N, step;
	vector<vector<int>> adj;
	vector<int> match, used;

	BTM(int N) : N(N), adj(N), match(vector<int>(N, -1)), used(N), step(0){}

	void add_edge(int l, int r){ adj[l].push_back(r); }

	bool dfs(int v){
		used[v] = step;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i], w = match[u];
			if (w < 0 || used[w] != step && dfs(w)){
				match[v] = u; match[u] = v;
				return true;
			}
		}
		return false;
	}

	int maxbtm(){
		int sum = 0;
		for (int v = 0; v < N; v++){
			if (match[v] == -1){
				++step;
				if (dfs(v)) sum++;
			}
		}
		return sum;
	}
};

char s[51];
bool love[50][50];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", s);
		for(int j = 0; j < N; j++)
			love[i][j] = (s[j] == '1');
	}

	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				love[i][j] |= love[i][k] & love[k][j];

	BTM btm(2 * N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(love[i][j]) btm.add_edge(i, N + j);

	printf("%d\n", N - btm.maxbtm());

	return 0;
}
