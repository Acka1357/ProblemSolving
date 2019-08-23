#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

int main()
{
	int N, K; scanf("%d %d", &N, &K);

	for(int s = min(N - 1, K); s >= 0; s--){
		int cnt = 0;
		for(int i = s; i < N; i += 2 * K + 1){
			if(i + K + 1 <= N - 1 && N - 1 <= i + 2 * K){
				cnt = -1;
				break;
			}
			cnt++;
		}
		if(cnt < 0) continue;

		printf("%d\n", cnt);
		for(int i = s; i < N; i += 2 * K + 1)
			printf("%d ", i + 1);
		printf("\n");
		break;
	}

	return 0;
}
