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
#include <set>
#include <map>
using namespace std;

typedef long long ll;

char s[200001], ans[200001];

int main()
{
	int L, T; scanf("%d %d %s", &L, &T, s);

	for(int i = 0; i < L / 2; i++)
		swap(s[i], s[L - i - 1]);

	int ansi = -1;
	for(int i = 0; s[i] != '.'; i++)
		if(s[i] >= '5') ansi = i;

	if(ansi < 0){
		for(int i = L - 1; i >= 0; i--)
			printf("%c", s[i]);
		return !printf("\n");
	}

	int ansl = 0, carry = 1, dot = 0;
	for(int i = ansi + 1; s[i]; i++){
		if(s[i] == '.'){
			dot = true;
			if(ansl) ans[ansl++] = '.';
			continue;
		}
		s[i] += carry;

		if(s[i] > '9'){
			carry = 1;
			s[i] -= 10;
		}
		else if(!dot && s[i] == '5' && --T > 0){
			carry = 1;
			ansl = 0;
			s[i] = '0';
		}
		else carry = 0;
		if(ansl || s[i] != '0' || dot) 
			ans[ansl++] = s[i];
	}

	if(carry) printf("1");
	for(int i = ansl - 1; i >= 0; i--)
		printf("%c", ans[i]);
	printf("\n");

	return 0;
}
