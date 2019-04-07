#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

char s[1001];

int main()
{
	scanf("%s", s);
	for(int i = 0; s[i]; i++){
		if(s[i + 1]) printf("%d ", s[i] != s[i + 1]);
		else printf("%d ", s[i] == 'a');
	}

	return 0;
}