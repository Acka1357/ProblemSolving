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

char s[200005];

int main()
{
	int L; scanf("%d %s", &L, s);
	int lsum = 0, rsum = 0, lcnt = 0, rcnt = 0;
	for(int i = 0; i < L / 2; i++){
		if(s[i] == '?') lcnt++;
		else lsum += s[i] - '0';
	}
	for(int i = L / 2; i < L; i++){
		if(s[i] == '?') rcnt++;
		else rsum += s[i] - '0';
	}

	if(lsum + 9 * lcnt / 2 < rsum + 9 * rcnt / 2) printf("Monocarp\n");
	else if(lsum + 9 * lcnt / 2 > rsum + 9 * rcnt / 2) printf("Monocarp\n");
	else printf("Bicarp\n"); 

	return 0;
}