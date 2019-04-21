#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

bool chk[10001];
vector<int> adj[10001];

int count(int cur){
	chk[cur] = true;
	int sum = 1;
	for(int &nxt : adj[cur])
		if(!chk[nxt])
			sum += count(nxt);
	return sum;
}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 0, u, v; i < M; i++){
		scanf("%d %d", &u, &v);
		adj[v].push_back(u);
	}

	vector<int> ans;
	int ans_cnt = 0;
	for(int i = 1; i <= N; i++){
		memset(chk, false, (N + 1) * sizeof(chk[0]));
		int cnt = count(i);
		if(cnt > ans_cnt) ans.clear();
		if(cnt >= ans_cnt){
			ans.push_back(i);
			ans_cnt = cnt;
		}
	}

	for(int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);

	return 0;
}