#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <memory.h>
using namespace std;

char s[102];
int cnt[101][3];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		scanf("%s", s + 1);

		int len = strlen(s + 1);
		for(int i = 1; i <= len; i++){
			cnt[i][0] = cnt[i - 1][0] + ('a' <= s[i] && s[i] <= 'z');
			cnt[i][1] = cnt[i - 1][1] + ('A' <= s[i] && s[i] <= 'Z');
			cnt[i][2] = cnt[i - 1][2] + ('0' <= s[i] && s[i] <= '9');
		}

		if(cnt[len][0] && cnt[len][1] && cnt[len][2]);
		else if((cnt[len][0] ? 1 : 0) + (cnt[len][1] ? 1: 0) + (cnt[len][2] ? 1: 0) == 2){
			if(cnt[len][0] >= 2){
				for(int i = 1; i <= len; i++)
					if('a' <= s[i] && s[i] <= 'z'){
						s[i] = (cnt[len][1] ? '0' : 'A');
						break;
					}			
			}
			else if(cnt[len][1] >= 2){
				for(int i = 1; i <= len; i++)
					if('A' <= s[i] && s[i] <= 'Z'){
						s[i] = (cnt[len][0] ? '0' : 'a');
						break;
					}			
			}
			else{
				for(int i = 1; i <= len; i++)
					if('0' <= s[i] && s[i] <= '9'){
						s[i] = (cnt[len][0] ? 'A' : 'a');
						break;
					}			
			}
		}
		else if(cnt[len][0]){
			s[1] = '0'; s[2] = 'A';
		}
		else if(cnt[len][1]){
			s[1] = '0'; s[2] = 'a';
		}
		else{
			s[1] = 'A'; s[2] = 'a';
		}

		printf("%s\n", s + 1);
	}
	return 0;
}
