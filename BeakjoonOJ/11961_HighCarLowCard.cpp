#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

bool notmy[100001];
int es[50002], d1[50002], d2[50002];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &es[i]);
		notmy[es[i]] = true;
	}

	set<int> bs;
	for(int i = 1; i <= 2 * N; i++)
		if(!notmy[i]) bs.insert(i);

	for(int i = 1; i <= N; i++){
		d1[i] = d1[i - 1];
		set<int>::iterator it = bs.upper_bound(es[i]);
		if(it != bs.end()) d1[i]++, bs.erase(it);
	}

	bs.clear();
	for(int i = 1; i <= 2 * N; i++)
		if(!notmy[i]) bs.insert(i);

	for(int i = N; i > 0; i--){
		d2[i] = d2[i + 1];
		set<int>::iterator it = bs.upper_bound(es[i]);
		if(it != bs.begin()) d2[i]++, bs.erase(--it);
	}

	int ans = 0;
	for(int i = 0; i <= N; i++){
		printf("%d %d %d %d\n", i, d1[i] + d2[i + 1], d1[i], d2[i + 1]);
		ans = max(ans, d1[i] + d2[i + 1]);
	}

	printf("%d\n", ans);
	return 0;
}