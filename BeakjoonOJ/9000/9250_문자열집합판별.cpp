//
// Created by Acka on 2017. 5. 2..
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Node{
    Node *next[26], *fail;
    bool actual;
    Node(){
        memset(this, 0, sizeof(this));
    }
};

Node root, nodes[100000];
int used = 0;
char str[10001];

void add_pattern(char *p){
    Node *cur = &root;
    for(int i = 0, alp; p[i]; i++){
        alp = p[i] - 'a';
        if(!(cur->next[alp]))
            cur->next[alp] = &nodes[used++];
        cur = cur->next[alp];
    }
    cur->actual = true;
}

void set_fail_link(){
    root.fail = &root;
    queue<Node*> q;
    q.push(&root);

    while(!q.empty()){
        Node *cur = q.front(); q.pop();
        for(int i = 0; i < 26; i++){
            Node *next = cur->next[i], *fail = cur->fail;
            if(!next) continue;
            while(fail != &root && fail->next[i] == NULL)
                fail = fail->fail;
            if(cur != &root && fail->next[i]) next->fail = fail->next[i];
            else next->fail = &root;

            if(next->fail->actual) next->actual = true;
            q.push(next);
        }
    }
}

bool is_matching(char *s){
    Node *cur = &root;
    for(int i = 0, alp; s[i]; i++){
        alp = s[i] - 'a';
        while(cur != &root && cur->next[alp] == NULL)
            cur = cur->fail;
        if(cur->next[alp]) cur = cur->next[alp];
        if(cur->actual) return true;
    }
    return false;
}

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", str);
        add_pattern(str);
    }

    set_fail_link();

    int Q; for(scanf("%d", &Q); Q--;){
        scanf("%s", str);
        printf("%s\n", is_matching(str) ? "YES" : "NO");
    }

    return 0;
}
