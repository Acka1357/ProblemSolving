#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int ans[50000], ai, turn;

int main()
{
	int N, K, P; scanf("%d %d %d", &N, &K, &P);

	queue<int> q;
	for(int i = 1; i <= K; i++)
		q.push(i);

	while(!q.empty()){
		if(turn == N - 1) ans[ai++] = q.front();
		turn = (turn + 1) % N;
		q.pop();
		if(q.empty()) break;
		for(int i = 0; i < P; i++){
			q.push(q.front());
			q.pop();
		}
	}

	sort(ans, ans + ai);
	for(int i = 0; i < ai; i++)
		printf("%d\n", ans[i]);

	return 0;
}