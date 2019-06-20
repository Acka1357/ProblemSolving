/*
	2019 Ajou Univ. Programming Contest
	아름다운 만영로 - 서브태스크2
	Acka's cpp solution
	Time Complexity: O(26 * (N + |P|))
*/

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct Edge{ int to; char c; };

int sl, ans, sf[500001], fi[500001][26];
char s[500001], cs[500001];
vector<Edge> ch[500001];

void search(int cur, int si, int depth){
	if(depth > 0){
		int ps = si;
		while(fi[si][cs[depth - 1] - 'a'] < 0 
			  && si > 0 && s[si] != cs[depth - 1])
			si = sf[si - 1];

		if(fi[si][cs[depth - 1] - 'a'] < 0){
			if(s[si] == cs[depth - 1]) si++;
		}
		else si = fi[si][cs[depth - 1] - 'a'];
		fi[ps][cs[depth - 1] - 'a'] = si;
	}
	if(si == sl) ans++, si = sf[si - 1];

	for(Edge &e : ch[cur]){
		cs[depth] = e.c;
		search(e.to, si, depth + 1);
	}
}

int main()
{
	int N; scanf("%d", &N);
	char tmp;
	for(int i = 1, u, v; i < N; i++){
		scanf("%d %d %c", &u, &v, &tmp);
		ch[u].push_back({v, tmp});
	}
	scanf("%s", s);
	sl = strlen(s);

	for(int i = 1, j = 0; i < sl; i++){
		while(j > 0 && s[j] != s[i]) j = sf[j - 1];
		sf[i] = (s[j] == s[i]) ? ++j : j;
	}

	memset(fi, 0xff, sizeof(fi));

	search(1, 0, 0);
	printf("%d\n", ans);

	return 0;
}
