//
// Created by Acka on 9/17/16.
//

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

struct KMP{
    vector<int> pi, cnt;
    int pl;
    char *s, *p;
    KMP(){} KMP(char *s, char *p): pi(vector<int>(pl = strlen(p))), cnt(vector<int>(pl + 1)), s(s), p(p){}
    vector<int>& get_pi(){
        for(int i = 1, j = 0; p[i]; i++){
            while(j && (p[i] != p[j]))
                j = pi[j - 1];
            if(p[i] == p[j]) pi[i] = ++j;
        }
        return pi;
    }
    vector<int>& get_counts(){
        get_pi();
        for(int i = 0, j = 0; s[i]; i++){
            while(j && (s[i] != p[j]))
                j = pi[j - 1];
            if((s[i] == p[j])){
                cnt[++j]++;
                if(j == pl) j = pi[j - 1];
            }
        }
        return cnt;
    }
};

char s[5001];

int main()
{
    scanf("%s", s);

    int ans = 0, len = strlen(s);
    for(int i = 0; (ans < len - i) && s[i]; i++){
        KMP kmp(s, s + i);
        vector<int> cnt = kmp.get_counts();
        for(int j = cnt.size() - 1; ans < j && 0 <= j; j--)
            if(2 <= cnt[j]) ans = j;
    }

    printf("%d\n", ans);
    return 0;
}