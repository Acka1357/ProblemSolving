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

typedef long long ll;

int len;
char s[200001], ans[200001], tmp[200001];

bool psb(int d){
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < len; i++){
		if(s[i] == '('){
			if(cnt1 == d && cnt2 == d) return false;
			if(cnt1 == d) tmp[i] = '1', cnt2++;
			else tmp[i] = '0', cnt1++;
		}
		else{
			if(!cnt1 && !cnt2) return false;
			if(!cnt1) tmp[i] = '1', cnt2--;
			else tmp[i] = '0', cnt1--;
		}
	}
	return (cnt1 == 0) && (cnt2 == 0);
}

int main()
{
	scanf("%d %s", &len, s);

	int l = 0, r = len, m;
	while(l <= r){
		m = (l + r) / 2;
		if(psb(m)){
			memcpy(ans, tmp, len);
			r = m - 1;
		}
		else l = m + 1;
	}
	printf("%s\n", ans);

	return 0;
}
