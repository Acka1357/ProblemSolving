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

char s[105];

int main()
{
	scanf("%s", s);

	bool chk = false;
	for(int i = 1; s[i]; i++)
		if(s[i] == '1') chk = true;

	int len = strlen(s);
	if(len & 1) printf("%d\n", len / 2 + chk);
	else printf("%d\n", len / 2);

	return 0;
}