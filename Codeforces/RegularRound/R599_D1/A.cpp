#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

bool np[1000006];
vector<int> ps;

void set_p(){
	for(ll i = 2; i <= 1000000; i++){
		if(np[i]) continue;
		ps.push_back(i);
		for(ll j = i * i; j <= 1000000; j += i)
			np[j] = true;
	}
}

int main()
{
	set_p();

	ll O, X; scanf("%lld", &X); O = X;
	if(X == 1) return !printf("1\n");

	vector<ll> p;
	for(int i = 0; i < (int)ps.size(); i++){
		if(X % ps[i]) continue;
		p.push_back(ps[i]);
		while(X % ps[i] == 0) X /= ps[i];
	}

	if(X != 1) p.push_back(X);
	if(p.size() == 1){
		if(O == p[0]) printf("%lld\n", O);
		else printf("%lld\n", (ll)p[0]);
	}
	else printf("1\n");

	return 0;
}