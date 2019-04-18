#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ull mod = 1000000007;

ull cum_s(ull idx){
	if(idx <= 0) return 0;
	ull turn = 0, ot = 0, et = 0, seg = 1;
	while(ot + et + seg <= idx){
		if(turn & 1) et += seg;
		else ot += seg;
		turn++;
		seg <<= 1;
	}
	if(turn & 1) et += idx - (ot + et);
	else ot += idx - (ot + et);

	et %= mod; ot %= mod;
	ull osum = ot + ot * (ot - 1);
	ull esum = 2 * et + et * (et - 1);
	return ((osum % mod) + (esum % mod)) % mod;
}

int main()
{
	ull L, R; scanf("%llu %llu", &L, &R);
	printf("%llu\n", (cum_s(R) - cum_s(L - 1) + mod) % mod);
	return 0;
}
