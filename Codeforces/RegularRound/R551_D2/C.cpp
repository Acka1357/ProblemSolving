#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
using namespace std;

typedef long long ll;

char s[300001];

int main()
{
	int L; scanf("%d %s", &L, s);
	int orem = L / 2, crem = L / 2;
	for(int i = 0; i < L; i++){
		orem -= s[i] == '(';
		crem -= s[i] == ')';
	}
	if((L & 1) || orem < 0 || crem < 0)
		return !printf(":(\n");

	int cnt = 0;
	for(int i = 0; i < L; i++){
		if(s[i] == '?'){
			if(orem){ s[i] = '('; orem--; }
			else s[i] = ')';
		}
		if(s[i] == '(') cnt++;
		else cnt--;
		if(cnt < 0 || (!cnt && i != L - 1)) return !printf(":(\n");
	}
	printf("%s\n", cnt ? ":(" : s);

	return 0;
}