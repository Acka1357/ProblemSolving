#include <cstdio>
#include <algorithm>
using namespace std;

struct Event{
	int s, e;
	bool operator <(const Event &o)const{
		return e == o.e ? s > o.s : e < o.e;
	}
};
x
Event e[10000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &e[i].s, &e[i].e);
		e[i].e += e[i].s;
	}

	sort(e, e + N);

	int ans = 0, last = 0;
	for(int i = 0; i < N; i++)
		if(e[i].s >= last){
			ans++, last = e[i].e;
		}
	printf("%d\n", ans);

	return 0;
}