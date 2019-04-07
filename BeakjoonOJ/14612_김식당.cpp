#include <stdio.h>
#include <algorithm>
using namespace std;

struct Order{
	int n, t;
	Order(){} Order(int n, int t):n(n), t(t){}
	bool operator <(const Order &o)const{
		return t == o.t ? n < o.n : t < o.t;
	}
};

Order o[100];

int main()
{
	int N, M; scanf("%d %d", &N, &M);

	int n, t, cnt = 0;
	char cmd[10];
	for(int i = 0; i < N; i++){
		scanf("%s", cmd);
		if(cmd[0] == 'o'){
			scanf("%d %d", &n, &t);
			o[cnt++] = Order(n, t);
		}
		else if(cmd[0] == 'c'){
			scanf("%d", &n);
			int i = 0;
			while(o[i].n != n) i++;
			while(i++ < cnt) o[i - 1] = o[i];
			cnt--;
		}
		else sort(o, o + cnt);

		if(cnt){
			for(int i = 0; i < cnt; i++)
				printf("%d ", o[i].n);
			printf("\n");
		}
		else printf("sleep\n");
	}
	return 0;
}
