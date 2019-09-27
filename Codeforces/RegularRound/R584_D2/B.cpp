#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int MAX = 100000;

struct Q{ int a, cmd; };

queue<Q> q[MAX + 1];
char s[105];
int on;

int main()
{
	int N; scanf("%d %s", &N, s);
	for(int i = 0, a, b; i < N; i++){
		scanf("%d %d", &a, &b);
		if(s[i] == '1'){
			on++;
			q[b].push({a, 0});
		}
		else q[b].push({a, 1});
	}

	int ans = on;
	for(int i = 1; i <= MAX && ans != N; i++){
		while(!q[i].empty()){
			int a = q[i].front().a, cmd = q[i].front().cmd; q[i].pop();
			if(cmd == 1){
				on++;
				if(i + a <= MAX) q[i + a].push({a, 0});
			}
			else{
				on--;
				if(i + a <= MAX) q[i + a].push({a, 1});
			}
		}
		ans = max(ans, on);
	}
	printf("%d\n", ans);

	return 0;
}
