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
using namespace std;

char s[101];
int a[100], cnt[101], one, two;

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	for(int i = 1; i <= 100; i++){
		if(cnt[i] == 1) one++;
		else if(cnt[i] == 2) two++;
	}

	if(N == one && one % 2) return !printf("NO\n");
	if(N == one + 2 * two && one % 2) return !printf("NO\n");

	printf("YES\n");

	int ot = 0;
	for(int i = 0; i < N; i++){
		if(cnt[a[i]] == 1){
			s[i] = 'A' + ot;
		 	ot = 1 - ot;
		}
		else s[i] = 'A';
	}

	if(one & 1){
		for(int i = 0; i < N; i++)
			if(cnt[a[i]] > 2){
				s[i] = 'B';
				break;
			}
	}

	printf("%s\n", s);
	return 0;
}
