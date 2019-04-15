#include <cstdio>
#include <algorithm>
using namespace std;

struct Cow{
	int a, b, idx;
	bool operator <(const Cow &o)const{
		return a > o.a;
	}
};

Cow cow[50000];

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &cow[i].a, &cow[i].b);
		cow[i].idx = i + 1;
	}

	sort(cow, cow + N);

	int ans = -1, ansb = -1;
	for(int i = 0; i < K; i++)
		if(cow[i].b > ansb){
			ans = cow[i].idx;
			ansb = cow[i].b;
		}
	printf("%d\n", ans);

	return 0;
}