/*
	2019 Ajou Univ. Programming Contest
	문자열 장식 - 서브태스크2
	Acka's cpp solution
	Time Complexity: O(N * (|S| + |P|))
*/

#include <cstdio>
#include <queue>
#include <algorithm>
#include <assert.h>
using namespace std;

char p[100][10001], s[500001];
int sl, pl[100], pi[100][10001];
queue<int> mi[100];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %s", &pl[i], p[i]);
		for(int j = 1, k = 0; j < pl[i]; j++){
			while(k > 0 && p[i][j] != p[i][k])
				k = pi[i][k - 1];
			pi[i][j] = (p[i][j] == p[i][k] ? ++k : k);
		}
	}

	scanf("%d %s", &sl, s);
	for(int i = 0; i < N; i++){
		int j = 0;
		for(int si = 0; si < sl; si++){
			while(j > 0 && p[i][j] != s[si])
				j = pi[i][j - 1];
			if(p[i][j] == s[si]) j++;
			if(j == pl[i]){
				mi[i].push(si);
				j = pi[i][j - 1];
			}
		}
	}

	for(int i = 0; i < N; i++)
		assert(!mi[i].empty());

	int ans = sl, r = 0;
	for(int l = 0; l < sl; l++){
		for(int i = 0; i < N; i++){
			while(!mi[i].empty() && mi[i].front() - pl[i] + 1 < l)
				mi[i].pop();
			if(mi[i].empty()) return !printf("%d\n", ans);
			r = max(r, mi[i].front());
		}
		ans = min(ans, r - l + 1);
	}
	printf("%d\n", ans);

	return 0;
}