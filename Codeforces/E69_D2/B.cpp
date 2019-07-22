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

int a[200000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int s = 0;
	for(int i = 1; i < N; i++)
		if(a[s] < a[i]) s = i;

	int l = s - 1, r = s + 1, top = a[s];
	while(l >= 0 || r < N){
		if(l < 0){
			if(a[r] > top) return !printf("NO\n");
			top = a[r++];
		}
		else if(r >= N){
			if(a[l] > top) return !printf("NO\n");
			top = a[l--];
		}
		else{
			if(a[l] > top || a[r] > top)
				return !printf("NO\n");
			else if(a[l] > a[r]) top = a[l--];
			else top = a[r++];
		}
	}
	printf("%s\n", l == -1 && r == N ? "YES" : "NO");

	return 0;
}
