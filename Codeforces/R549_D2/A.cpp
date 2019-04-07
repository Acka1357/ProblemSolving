#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <utility>
using namespace std;

typedef long long ll;

int N, ansl, ansr;

int main()
{
	scanf("%d", &N);
	for(int i = 1, a; i <= N; i++){
		scanf("%d", &a);
		if(a) ansr = i;
		else ansl = i;
	}
	printf("%d\n", ansr < ansl ? ansr : ansl);
	
	return 0;
}
