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

char s[101];

bool chk(char* str, int len){
	for(int i = 1; i < len; i++)
		if(str[i] == str[i - 1] + 1 || str[i] == str[i - 1] - 1)
			return false;
	return true;
}

void print_ans(char* ss, int ssl, int *cnt){
	for(int i = 0; i < ssl; i++){
		while(cnt[ss[i] - 'a']){
			printf("%c", ss[i]);
			cnt[ss[i] - 'a']--;
		}
	}
	printf("\n");
}

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int cnt[26] = {0,};
		char ss[27] = {0,}, ans[27] = {0,};
		scanf("%s", s);
		int len = strlen(s), ssl = 1;
		sort(s, s + len);
		cnt[s[0] - 'a']++;
		ss[0] = s[0];
		for(int i = 1; i < len; i++){
			cnt[s[i] - 'a']++;
			if(s[i] != s[i - 1]) ss[ssl++] = s[i];
		}

		for(int i = 0; i < ssl; i++){
			if(i < ssl / 2) ans[i * 2 + 1] = ss[i];
			else ans[2 * (i - ssl / 2)] = ss[i];
		}
		if(chk(ans, ssl)){
			print_ans(ans, ssl, cnt);
			continue;
		}
		
		for(int i = 0; i < ssl; i++){
			if(i <= (ssl - 1) / 2) ans[i * 2] = ss[i];
			else ans[2 * (i - (ssl + 1) / 2) + 1] = ss[i];
		}
		if(chk(ans, ssl)){
			print_ans(ans, ssl, cnt);
			continue;
		}
		printf("No answer\n");
	}
	return 0;
}
