#include <stdio.h>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

struct Node{
	int sum;
	char cur[101];
	Node(){}
	Node(int s, char *b){sum = s, strcpy(cur, b);}
	bool operator <(const Node &o)const{
		return sum < o.sum;
	}
};

vector<Node> made[101];
char p[100][101], s[101], s0[101], s1[101];
int N, M, P, d[101][2], ans;

bool can(char *b){
	for(int i = 0; i < M; i++)
		if(!strcmp(p[i], b)) return false;
	return true;
}

int main()
{
   // freopen("/Users/Acka/Library/Mobile Documents/com~apple~CloudDocs/Desktop/ProblemSolving/src/Codejam/18_Kickstart_E/B-large.in", "r", stdin);
   // freopen("/Users/Acka/Library/Mobile Documents/com~apple~CloudDocs/Desktop/ProblemSolving/src/Codejam/18_Kickstart_E/B-large.out", "w", stdout);

	s[0] = 0;
	made[0].push_back(Node(0, s));

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		scanf("%d %d %d", &N, &M, &P);

		memset(d, 0, sizeof(d));
		for(int i = 0; i < N; i++){
			scanf("%s", s);
			for(int j = 0; j < P; j++)
				d[j][1 - s[j] + '0']++;
		}

		for(int i = 0; i < M; i++)
			scanf("%s", p[i]);
		
		int ans = N * P, K = M + 1;
		for(int i = 0; i < P; i++){
			made[i + 1].clear();
			for(int j = min((int)made[i].size(), K) - 1; j >= 0; j--){
				strcpy(s0, made[i][j].cur);
				strcpy(s1, s0);
				s0[i] = '0', s1[i] = '1';
				s0[i + 1] = s1[i + 1] = 0;
				made[i + 1].push_back(Node(made[i][j].sum + d[i][0], s0));
				made[i + 1].push_back(Node(made[i][j].sum + d[i][1], s1));				
			}
			sort(made[i + 1].begin(), made[i + 1].end());
		}

		for(int i = 0; i < made[P].size(); i++)
			if(can(made[P][i].cur)){
				printf("Case #%d: %d\n", tc, made[P][i].sum);
				break;
			}	
	}
	return 0;
}
