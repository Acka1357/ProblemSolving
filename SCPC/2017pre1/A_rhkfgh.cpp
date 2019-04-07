//
// Created by Acka on 2017. 6. 30..
//

#include <stdio.h>
#include <string.h>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Info{
    int left, len;
    Info(){}
    Info(int i, int l):left(i), len(l){}
    bool operator <(const Info &A)const{
        return len > A.len;
    }
};

int maxl[10000001];
char s[10000001];
char match[256];

int main()
{
    match['('] = ')';
    match['{'] = '}';
    match['['] = ']';

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        scanf("%s", s);

        priority_queue<Info> q;
        int sl = strlen(s);
        memset(maxl, 0, sizeof(sl));
        for(int i = 1; i < sl; i++)
            if(match[s[i - 1]] == s[i]){
                q.push(Info(i - 1, 2));
                maxl[i - 1] = 2;
            }

        while(!q.empty()){
            int left = q.top().left, len = q.top().len; q.pop();
            if(maxl[left] > len) continue;
            if(maxl[left + len]){
                q.push(Info(left, len + maxl[left + len]));
                maxl[left] = len + maxl[left + len];
            }
            if(left && left + len < sl){
                if(match[s[left - 1]] == s[left + len]){
                    if(maxl[left - 1] < len + 2) {
                        q.push(Info(left - 1, len + 2));
                        maxl[left - 1] = len + 2;
                    }
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < sl; i++)
            ans = max(ans, maxl[i]);

        printf("Case #%d\n%d\n", tc, ans);
    }
    return 0;
}

