#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory.h>
using namespace std;

int par[202], chk[202][2], cnt;
string A, B, name[202];
map<string, int> mp;

void set_chk(int cur, int dist, int idx){
	chk[cur][idx] = dist;
	if(par[cur] >= 0) set_chk(par[cur], dist + 1, idx);
}

int main()
{
	memset(par, 0xff, sizeof(par));
	memset(chk, 0xff, sizeof(chk));

	int N; cin >> N >> A >> B;
	mp[name[cnt] = A] = cnt; cnt++;
	mp[name[cnt] = B] = cnt; cnt++;
	for(int i = 0; i < N; i++){
		cin >> A >> B;
		if(!mp.count(A)) mp[name[cnt] = A] = cnt, cnt++;
		if(!mp.count(B)) mp[name[cnt] = B] = cnt, cnt++;
		par[mp[B]] = mp[A];
	}

	set_chk(0, 0, 0);
	set_chk(1, 0, 1);

	int lca = -1;
	for(int i = 0; i < cnt; i++){
		if(chk[i][0] < 0 || chk[i][1] < 0) continue;
		if(lca < 0 || (chk[i][0] + chk[i][1] < chk[lca][0] + chk[lca][1]))
			lca = i;
	}
	
	string ans;
	if(lca < 0) ans = "NOT RELATED";
	else if(chk[lca][0] == 1 && chk[lca][1] == 1) ans = "SIBLINGS";
	else if(lca == 0 || lca == 1){
		ans = (lca == 0 ? name[0] : name[1]) + " is the ";
		for(int i = max(chk[lca][0], chk[lca][1]) - 2; i > 0; i--)
			ans += "great-";
		if(max(chk[lca][0], chk[lca][1]) > 1) ans += "grand-";
		ans += "mother of " + (lca == 0 ? name[1] : name[0]);
	}
	else if(chk[lca][0] == 1 || chk[lca][1] == 1){
		ans = (chk[lca][0] == 1 ? name[0] : name[1]) + " is the ";
		for(int i = max(chk[lca][0], chk[lca][1]) - 2; i > 0; i--)
			ans += "great-";
		ans += "aunt of " + (chk[lca][0] == 1 ? name[1] : name[0]);
	}
	else ans = "COUSINS";
	cout << ans << "\n";

	return 0;
}
