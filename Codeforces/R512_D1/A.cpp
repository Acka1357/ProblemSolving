#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
#include <map>
using namespace std;

int p[10000], pcnt, f[10000], fcnt[10000];
bool notP[34000] = {true, true};

void set_p(){
	for(int i = 2; i < 34000; i++){
		if(notP[i]) continue;
		p[pcnt++] = i;
		for(int j = i * i; j < 34000; j++)
			notP[j] = true;
	}
}

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
	long long n, m, k; scanf("%lld %lld %lld\n", &n, &m, &k);
	
	long long up = n * m;
	long long g = gcd(up, k);
	if(k / g > 2) return !printf("NO\n");

	up /= g;
	int fi = 0;
	for(int i = 0; i < pcnt; i++){
		if(up % p[i]) continue;
		while(up % p[i] == 0){
			fcnt[fi]++;
			up /= p[i];
		}
		f[fi++] = p[i];
	}
	if(up > 1){ f[fi] = up; fcnt[fi++] = 1;}

	if(k / g == 1){
		long long w = 1, h = 1;
		for(int i = 0; i < fi; i++){
			long long x = 1, xcnt = 0;
			while(xcnt < fcnt[i] && n % x == 0){
				x *= f[i];
				xcnt++;
			}
			w *= x;
			while(xcnt < fcnt[i]){
				h *= f[i];
				xcnt++;
			}
		}
		if(w * 2 <= n){
			printf("YES\n");
			printf("%lld %lld\n", 0 , 0);
			printf("%lld %lld\n", 2 * w, 0);
			printf("%lld %lld\n", 0, h);
			return 0;
		}
		else if(h * 2<= m){
			printf("YES\n");
			printf("%lld %lld\n", 0 , 0);
			printf("%lld %lld\n", w, 0);
			printf("%lld %lld\n", 0, 2 * h);
			return 0;
		}

		w = 1; h = 1;
		for(int i = 0; i < fi; i++){
			long long x = 1, xcnt = 0;
			while(xcnt < fcnt[i] && m % x == 0){
				x *= f[i];
				xcnt++;
			}
			h *= x;
			while(xcnt < fcnt[i]){
				w *= f[i];
				xcnt++;
			}
		}
		if(w * 2 <= n){
			printf("YES\n");
			printf("%lld %lld\n", 0 , 0);
			printf("%lld %lld\n", 2 * w, 0);
			printf("%lld %lld\n", 0, h);
			return 0;
		}
		else if(h * 2 <= m){
			printf("YES\n");
			printf("%lld %lld\n", 0 , 0);
			printf("%lld %lld\n", w, 0);
			printf("%lld %lld\n", 0, 2 * h);
			return 0;
		}

		return !printf("NO\n");
	}
	else{
		long long w = 1, h = 1;
		for(int i = 0; i < fi; i++){
			long long x = 1, xcnt = 0;
			while(xcnt < fcnt[i] && n % x == 0){
				x *= f[i];
				xcnt++;
			}
			w *= x;
			while(xcnt < fcnt[i]){
				h *= f[i];
				xcnt++;
			}
		}
		printf("YES\n");
		printf("%lld %lld\n", 0 , 0);
		printf("%lld %lld\n", w, 0);
		printf("%lld %lld\n", 0, h);
	}
	return 0;
}
