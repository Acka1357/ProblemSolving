#include <stdio.h>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
	long long c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

int main()
{
	long long a, b, x, y; scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
	long long g = gcd(x, y);
	x /= g; y /= g;
	printf("%lld\n", min(a / x, b / y));
	return 0;
}
