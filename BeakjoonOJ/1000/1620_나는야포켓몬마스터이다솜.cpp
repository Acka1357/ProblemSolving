#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

char s[21], name[100001][21];
unordered_map<string, int> num;

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++){
		scanf("%s", name[i]);
		num[name[i]] = i;
	}

	while(M--){
		scanf("%s", s);
		if('0' <= s[0] && s[0] <= '9'){
			int n = 0;
			for(int i = 0; s[i]; i++)
				n = n * 10 + s[i] - '0';
			printf("%s\n", name[n]);
		}
		else printf("%d\n", num[s]);
	}

	return 0;
}
