#include <cstdio>
#include <queue>
using namespace std;

typedef long long ll;

struct Node{
	int b, s;
	bool operator <(const Node &o)const{
		return s > o.s;
	}
};

int main()
{
	int N; scanf("%d", &N);

	priority_queue<Node> q;
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x);
		if(!q.empty() && q.top().s < x){
			int b = q.top().b; q.pop();
			q.push({b, x});
		}
		q.push({x, x});
	}

	ll ans = 0;
	while(!q.empty()){
		ans += q.top().s - q.top().b;
		q.pop();
	}
	printf("%lld\n", ans);
	
	return 0;
}