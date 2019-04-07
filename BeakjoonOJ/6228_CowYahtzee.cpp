#include <cstdio>
#include <vector>
using namespace std;

struct Cond{ int n, cnt; };

char s[128];
int N, S, E, ans, cnt[9];
vector<vector<Cond>> cond;

void dfs(int idx){
	if(idx == N){
		for(vector<Cond> &c : cond){
			bool psb = true;
			for(Cond &con : c)
				if(cnt[con.n] < con.cnt){
					psb = false;
					break;
				}
			if(psb){
				ans++; return ;
			}
		}
		return ;
	}

	for(int i = 1; i <= S; i++){
		cnt[i]++;
		dfs(idx + 1);
		cnt[i]--;
	}
}

int main()
{
	scanf("%d %d %d", &N, &S, &E);
	for(int i = 0; i < E; i++){
		scanf("%s", s);
		vector<Cond> c;
		for(int i = 0, w, r; s[i]; i++){
			sscanf(s + i, "%dx%d", &w, &r);
			c.push_back({r, w});
			while(s[i + 1] && s[i] != '+') i++;
		}
		cond.push_back(c);
	}

	dfs(0);
	printf("%d\n", ans);

	return 0;
}
