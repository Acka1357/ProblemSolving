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

int m[1002], d[1002];

int main()
{
	int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
		int K; scanf("%d", &K);
		for(int i = 0; i <= K; i++)
			scanf("%d", &m[i]);

		memset(d, 0xff, sizeof(d));
		d[0] = d[1] = 0;
		for(int i = 2; i <= K; i++){
			int minv = m[i - 1], maxv = m[i - 1];
			d[i] = d[i - 1];
			for(int j = i - 2; j >= 0; j--){
				if(minv < m[i] && minv < m[j])
					d[i] = max(d[i], d[j] + 1);
				if(maxv > m[i] && maxv > m[j])
					d[i] = max(d[i], d[j] + 1);
				minv = min(minv, m[j]);
				maxv = max(maxv, m[j]);
			}
		}
        printf("Case #%d: %d\n", tc, d[K] - 1);
    }
	return 0;
}
