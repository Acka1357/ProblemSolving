#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
using namespace std;

typedef long long ll;

int ans[100][100], fb[100], lr[100];

int main()
{
	int R, C, H; scanf("%d %d %d", &R, &C, &H);
	for(int i = 0; i < C; i++)
		scanf("%d", &fb[i]);
	for(int i = 0; i < R; i++)
		scanf("%d", &lr[i]);
	for(int i = 0, x; i < R; i++){
		for(int j = 0; j < C; j++){
			scanf("%d", &x);
			printf("%d ", x ? min(lr[i], fb[j]) : 0);
		}
		printf("\n");
	}

	return 0;
}