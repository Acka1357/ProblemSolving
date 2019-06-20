#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> to[10002];
int N, I, H, R, p[10002];

int main()
{
	scanf("%d %d %d %d", &N, &I, &H, &R);
	for(int i = 0, a, b; i < R; i++){
		scanf("%d %d", &a, &b);
		if(a > b) swap(a, b);
		to[a].push_back(b);
	}

	for(int i = 1, s = 0; i <= N; i++){
		sort(to[i].begin(), to[i].end());
		for(int j = 0; j < to[i].size(); j++)
			if(!j || to[i][j] != to[i][j - 1]){
				p[i + 1]--; p[to[i][j]]++;
			}
		printf("%d\n", H + (s += p[i]));
	}

	return 0;
}
