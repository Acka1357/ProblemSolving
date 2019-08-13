#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int BASE = 1000002;

char s[1000001];
int cum[1000001], len;
vector<int> idx[2 * BASE + 1];

int main()
{
	scanf("%s", s);
	int cur = BASE;
	for(len = 0; s[len]; len++){
		cur += (s[len] == '(' ? 1 : -1);
		cum[len] = cur;
		if(s[len] == ')') idx[cur].push_back(len);
	}

	int ans = 0, cnt = 0;
	for(int i = 0; i < len; i++){
		if(s[i] == ')' || !idx[cum[i] - 1].size()) continue;
		auto ed = upper_bound(idx[cum[i] - 2].begin(), idx[cum[i] - 2].end(), i);
		int limit = (ed == idx[cum[i] - 2].end() ? len : *ed);
		auto it = upper_bound(idx[cum[i] - 1].begin(), idx[cum[i] - 1].end(), limit);
		--it;
		if(i < *it){
			int len = *it - i + 1;
			if(ans < len) ans = len, cnt = 1;
			else if(ans == len) cnt++;
		}
	}
	printf("%d %d\n", ans, ans ? cnt : 1);

	return 0;
}
