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
using namespace std;

typedef long long ll;

int a[200000];

int main()
{
	int N, cnt1 = 0, cnt2 = 0; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		cnt1 += (a[i] == 1);
		cnt2 += (a[i] == 2);
	}

	if(cnt1 && cnt2){
		cnt1--; cnt2--;
		a[0] = 2; a[1] = 1;
		for(int i = 0; i < cnt2; i++)
			a[2 + i] = 2;
		for(int i = 0; i < cnt1; i++)
			a[2 + cnt2 + i] = 1;
	}
	
	for(int i = 0; i < N; i++)
			printf("%d%c", a[i], " \n"[i == N - 1]);		

	return 0;
}
