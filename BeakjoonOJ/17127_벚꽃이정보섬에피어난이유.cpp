#include <cstdio>
#include <algorithm>
using namespace std;

int N, a[10], ans;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	for(int i1 = 0, p1 = 1; i1 < N; i1++){
		p1 *= a[i1];
		for(int i2 = i1 + 1, p2 = 1; i2 < N; i2++){
			p2 *= a[i2];
			for(int i3 = i2 + 1, p3 = 1; i3 < N; i3++){
				p3 *= a[i3];
				for(int i4 = i3 + 1, p4 = 1; i4 < N; i4++){
					p4 *= a[i4];
					if(i4 == N - 1) ans = max(ans, p1 + p2 + p3 + p4);
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}