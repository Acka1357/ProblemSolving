#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Info{
	int what, when;
	Info(int m, int t):what(m), when(t){}
};

vector<Info> info[51];
int ill[51], chk[51], cchk[51][51];

int main()
{
	int N, M, D, S; scanf("%d %d %d %d", &N, &M, &D, &S);
	for(int i = 0, p, m, t; i < D; i++){
		scanf("%d %d %d", &p, &m, &t);
		info[p].push_back(Info(m, t));
	}
	for(int i = 0, p, t; i < S; i++){
		scanf("%d %d", &p, &t);
		ill[p] = t;
	}

	int all = 0;
	for(int i = 1; i <= N; i++)
		if(ill[i]){
			for(int j = 0; j < info[i].size(); j++)
				if(info[i][j].when < ill[i] && !cchk[i][info[i][j].what])
					chk[info[i][j].what]++, cchk[i][info[i][j].what] = 1;
			all++;
		}

	int ans = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j < info[i].size(); j++)
			if(chk[info[i][j].what] == all){
				ans++; break;
			}

	printf("%d\n", ans);
	return 0;
}