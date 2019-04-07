#include <cstdio>
#include <algorithm>
using namespace std;

struct Cow{
	int a, b, c;
	bool operator <(const Cow &o)const{
		return c < o.c;
	}
};

Cow cow[25000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &cow[i].a, &cow[i].b);
		if(cow[i].a < cow[i].b) cow[i].c = cow[i].a;
		else cow[i].c = 40000 - cow[i].b;
	}

	sort(cow, cow + N);

	int cum = 0, last = 0;
	for(int i = 0; i < N; i++){
		cum += cow[i].a;
		last = max(cum, last) + cow[i].b;
	}
	printf("%d\n", last);

	return 0;
}
