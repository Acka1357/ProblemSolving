#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> q;
	int N; scanf("%d", &N);
	for(int i = 0, x; i < N; i++){
		scanf("%d", &x);
		q.push(x);
	}

	long long sum = 0, l1, l2;
	while(q.size() > 1){
		l1 = q.top(); q.pop();
		l2 = q.top(); q.pop();
		sum += l1 + l2;
		q.push(l1 + l2);
	}
	printf("%lld\n", sum);

	return 0;
}
