#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int D, N, p[50000], pcnt, ans;
bool np[50000];

void set_p(){
	np[0] = np[1] = true;
	for(ll i = 2; i < 50000; i++){
		if(np[i]) continue;
		p[pcnt++] = i;
		for(ll j = i * i; j < 50000; j += i)
			np[j] = true;
	}
}

bool chk(int n){
	for(int i = 0; i < pcnt && n > p[i]; i++)
		if(n % p[i] == 0) return false;
	return true;
}

int main()
{
	set_p();

	scanf("%d %d", &D, &N);
	int dd = 1;
	for(int i = 1; i < D; i++) dd *= 10;
	N = max(N, dd * dd * 10);

	while(true){
		int r = N, l = 0, ld = 0, mod = 1;
		for(int i = 1; ; i++){
			ld = r % 10; r /= 10; mod *= 10; l = N % mod;
			if(r < dd) break;
			if(i >= D && ld && chk(r) && chk(l))
				return printf("%d\n", N) & 0;
		}
		N++;
	}

	return 0;
}
