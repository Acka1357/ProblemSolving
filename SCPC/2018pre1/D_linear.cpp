#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int edge[40][2];

int absx(int x){
	return x < 0 ? -x : x;
}

int calc(vector<int>& p, int M){
	int sum = 0;
	for(int i = 0; i < M; i++)
		sum += absx(p[edge[i][0]] - p[edge[i][1]]);
	return sum;
}

int main()
{
	setbuf(stdout, NULL);

	int T; scanf("%d", &T);
	for(int tc = 0; tc++ < T;){
		int N, M; scanf("%d %d", &N, &M);
		if(N >= 9){
			for(int i = 0; i < M; i++)
				scanf("%*d %*d");
			printf("Case #%d\n%d\n", tc, -1);
			for(int i = 0; i < N; i++)
				printf("%d ", i);
			printf("\n");
			continue;
		}

		for(int i = 0; i < M; i++)
			scanf("%d %d", &edge[i][0], &edge[i][1]);

		vector<int> p;
		for(int i = 0; i < N; i++)
			p.push_back(i);

		int ans = 987654321, ansp[9];
		do{
			int sum = calc(p, M);
			if(sum < ans){
				ans = sum;
				for(int i = 0; i < N; i++)
					ansp[p[i]] = i;
			}
		}while(next_permutation(p.begin(), p.end()));

		printf("Case #%d\n%d\n", tc, ans);
		for(int i = 0; i < N; i++)
			printf("%d ", ansp[i]);
		printf("\n");
	}
	return 0;
}