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

char ans[1000001], s[1000001];
int pi[1000001];

int main()
{
	int N; scanf("%d %s", &N, ans);

	int pl = strlen(ans);
    for(int i = 1; i < N; i++){
    	scanf("%s", s);

    	int l = strlen(s);
    	for(int i = 1, j = 0; s[i]; i++){
    		while(j && (s[i] != s[j]))
    			j = pi[j - 1];
    		if(s[i] == s[j]) pi[i] = ++j;
    		else pi[i] = 0;
    	}
    	pi[l] = 0;

    	int j = 0; 
    	for(int i = max(0, pl - l); ans[i]; i++){
    		while(j && (ans[i] != s[j]))
    			j = pi[j - 1];
    		if(ans[i] == s[j]) j++;
    	}

    	if(s[j]){
    		for(int i = j; i < l; i++)
    			ans[pl++] = s[i];
    	}
     }
    printf("%s\n", ans);

	return 0;
}
