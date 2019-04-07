#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

int a[20];

int main()
{
	int N, A, B; scanf("%d %d %d", &N, &A, &B);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for(int i = 0; i < N; i++){
		if(a[i] == 2){
			if(a[N - i - 1] == 2){
				ans += (i == N - i - 1 ? 1 : 2) * (A < B ? A : B);
				a[i] = a[N - i - 1] = (A < B ? 0 : 1);
			}
			else ans += (a[N - i - 1] == 0 ? A : B), a[i] = a[N - i - 1];
		}
		else if(a[i] != a[N - i - 1] && a[N - i - 1] != 2){
			ans = -1; break;
		}
	}

	printf("%d\n", ans);
	return 0;
}
