//
// Created by Acka on 9/16/16.
//

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

struct KMP{
    vector<int> pi, matchi;
    int pl;
    char *s, *p;
    KMP(){} KMP(char *s, char *p): pi(vector<int>(pl = strlen(p))), s(s), p(p){}
    vector<int>& get_pi(){
        for(int i = 1, j = 0; p[i]; i++){
            while(j && (p[i] != p[j]))
                j = pi[j - 1];
            if(p[i] == p[j]) pi[i] = ++j;
        }
        return pi;
    }
    vector<int>& get_matchs(){
        get_pi();
        for(int i = 0, j = 0; s[i]; i++){
            while(j && (s[i] != p[j]))
                j = pi[j - 1];
            if((s[i] == p[j]) && (++j == pl)){
                matchi.push_back(i - pl + 1);
                j = pi[j - 1];
            }
        }
        return matchi;
    }
};

char s[1000001], p[1000001];

int main()
{
    gets(s); gets(p);
    KMP kmp(s, p);
    vector<int>& ans = kmp.get_matchs();
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}

