#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Seg{ int l, r; };

vector<string> ans;
bool ex[201];
int oi[11], ocnt, pcnt;
char s[201];
Seg p[10];

void dfs(int cur){
	if(cur == pcnt){
		string str = "";
		for(int i = 0; s[i]; i++)
			if(!ex[i]) str += s[i];
		ans.push_back(str);
		return ;
	}
	ex[p[cur].l] = ex[p[cur].r] = true;
	dfs(cur + 1);
	ex[p[cur].l] = ex[p[cur].r] = false;
	dfs(cur + 1);
}

int main()
{
	scanf("%s", s);
	for(int i = 0; s[i]; i++){
		if(s[i] == '(') oi[ocnt++] = i;
		else if(s[i] == ')') p[pcnt++] = {oi[--ocnt], i};
	}

	dfs(0);
	ans.pop_back();
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(string str : ans)
		if(str.length()) printf("%s\n", str.c_str());

	return 0;
}
