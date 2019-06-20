/*
	2019 Ajou Univ. Programming Contest
	아싸 너! - 서브태스크3
	Acka's cpp solution
	Time Complexity: O(N^2)
*/

#include <cstdio>
#include <vector>
using namespace std;

vector<int> ans;

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	if(N % 2 == 0 && M % 2 == 0)
		return !printf("NO\n");

	int cur = 1;
	if(M <= N / 2){
		for(int cnt = (M - 1) / 2; cnt > 0; cnt--, cur += 2)
			for(int x = N - 1; x > 1; x--)
				ans.push_back(x);
	}
	else{
		cur = N + 1;
		for(int cnt = (N + 1 - M) / 2; cnt > 0; cnt--, cur -= 2)
			for(int x = 2; x < N; x++)
				ans.push_back(x);
	}

	if(cur < M){
		for(int i = 1; i < N; i++)
			ans.push_back((i & 1) ? (N - i) : (((N + 2 - i) % N) + 1));
	}
	else if(cur > M){
		for(int i = 1; i < N; i++)
			ans.push_back((i & 1) ? i + 2 : i - 1);
	}

	printf("YES\n%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	
	return 0;
}