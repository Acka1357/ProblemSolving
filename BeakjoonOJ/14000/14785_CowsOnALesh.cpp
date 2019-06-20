#include <cstdio>
#include <algorithm>
using namespace std;

struct Line{
	int s, l;
	bool operator <(const Line &o)const{
		return s == o.s ? l > o.l : s < o.s;
	}
};

Line line[32000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &line[i].s, &line[i].l);

	sort(line, line + N);

	int ans = 1, r = line[0].s + line[0].l;
	for(int i = 1; i < N; i++){
		if(line[i].s >= r){
			ans++;
			r = line[i].s + line[i].l;
		}
		r = min(r, line[i].s + line[i].l);
	}
	printf("%d\n", ans);

	return 0;
}