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

char s[300001];

int main()
{
	int L; scanf("%d %s", &L, s);
	for(int i = 1; i < L; i++)
		if(s[i] < s[i - 1])
			return !printf("YES\n%d %d\n", i, i + 1);

	return !printf("NO\n");
}
