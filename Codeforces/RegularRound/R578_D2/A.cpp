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

char s[100001], ans[11];

int main()
{
	int N; scanf("%d", &N);
	scanf("%s", s);

	memset(ans, '0', 10);
	for(int i = 0; i < N; i++){
		if(s[i] == 'L'){
			for(int j = 0; j < 10; j++)
				if(ans[j] == '0'){
					ans[j]++; break;
				}
		}
		else if(s[i] == 'R'){
			for(int j = 9; j >= 0; j--)
				if(ans[j] == '0'){
					ans[j]++; break;
				}
		}
		else{
			ans[s[i] - '0'] = '0';
		}
	}
	printf("%s\n", ans);

	return 0;
}
