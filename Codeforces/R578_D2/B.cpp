#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int h[101];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int N, R, K; scanf("%d %d %d", &N, &R, &K);
		for(int i = 0; i < N; i++)
			scanf("%d", &h[i]);

		bool psb = true;
		for(int i = 0; i < N - 1 && psb; i++){
			if(h[i] <= h[i + 1]){
				int gap = h[i + 1] - h[i];
				if(gap <= K) R += min(K - gap, h[i]);
				else if(gap <= K + R) R -= gap - K;
				else psb = false;
			}
			else R += min(h[i] - h[i + 1] + K, h[i]);
		}
		printf("%s\n", psb ? "YES" : "NO");
	}
	return 0;
}
