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

char s[100001];

int main()
{
	int N; scanf("%d %s", &N, s);
	int cnt = s[N - 11] == '8';
	for(int i = 0; i < N - 11; i++)
		cnt += s[i] == '8';
	printf("%s\n", cnt > (N - 11) / 2 ? "YES" : "NO");
	return 0;
}
