//
// Created by Acka on 2017. 10. 11..
//

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    char c;
    vector<Node*> next;
    Node(char c):c(c){}
};

Node root(0);
int N, L, nextn = 1, ans = 1000;

void add(char *s){
    Node *cur = &root, *next;
    bool chk = true;
    for(int i = L - 1; i >= 0; i--){
        bool ex = false;
        for(int j = 0; j < cur->next.size(); j++)
            if(cur->next[j]->c == s[i]){
                next = cur->next[j];
                ex = true;
                break;
            }
        if(!ex){
            if(chk){
                chk = false;
                ans = min(ans, i);
            }
            next = new Node(s[i]);
            cur->next.push_back(next);
        }
        cur = next;
    }
    if(chk) ans = 0;
}

char s[1000][1001];

int main()
{
    scanf("%d %d", &L, &N);
    for(int i = 0; i < L; i++)
        for(int j = 0; j < N; j++)
            scanf(" %c", &s[j][i]);

    for(int i = 0; i < N; i++)
        add(s[i]);

    printf("%d\n", ans);
    return 0;
}
