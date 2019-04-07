#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

typedef long long ll;

int main()
{
	int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
		int R, C, K; scanf("%d %d %d", &R, &C, &K);
		if(R * C - K == 1){
			printf("Case #%d: IMPOSSIBLE\n", tc);
			continue;
		}
		
		printf("Case #%d: POSSIBLE\n", tc);
		if(C == 1){
			for(int i = 0; i < R; i++) 
				printf("%c\n", i == K ? 'S' : 'N');
			continue;
		}

        int sum = 0, chk = 0;
        for(int i = 0; i < R; i++){
        	for(int j = 0; j < C; j++){
        		if(sum < K) printf("N");
        		else if(sum == K) printf("%c", j == C - 1 ? 'S' : 'E');
        		else if(j == C - 1) printf("W");
        		else printf("E");
        		sum++;
        	}
        	if(sum >= K) chk = 1;
        	printf("\n");
        }
    }
	return 0;
}
