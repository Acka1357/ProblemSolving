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

#define MAXP		3873
#define PCNT		536

map<int, int> cnt;
bool notP[3874] = {true, true,};
int p[PCNT], pcnt, a[300000];

void set_prime(){
	for(int i = 2; i <= MAXP; i++){
		if(notP[i]) continue;
		p[pcnt++] = i;
		for(int j = i * i; j <= MAXP; j += i)
			notP[j] = true;
	}
}

int gcd(int a, int b){
	int c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

int main()
{
	set_prime();

	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	int g = a[0];
	for(int i = 1; i < N; i++)
		g = gcd(g, a[i]);

	for(int i = 0; i < N; i++)
		a[i] /= g;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; a[i] > 1 && j < pcnt; j++){
			if(!(a[i] % p[j])) cnt[p[j]]++;
			while(!(a[i] % p[j])) a[i] /= p[j];
		}
		if(a[i] > 1) cnt[a[i]]++;
	}

	int ans = -1;
	for(auto it = cnt.begin(); it != cnt.end(); it++)
		ans = max(ans, it->second);
	printf("%d\n", ans < 0 ? ans : N - ans);

	return 0;
}
