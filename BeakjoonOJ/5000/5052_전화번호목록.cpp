//
// Created by Acka on 2017. 2. 12..
//

#include <stdio.h>
#include <memory.h>

struct Node{
    bool valid;
    Node* next[10];
};

int nidx;
Node node[100001];

int main()
{
    char s[11];
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        nidx = 1;
        memset(node, 0, (N * 10 + 1) * sizeof(node[0]));

        bool ans = true;
        for(int i = 0; i < N; i++){
            scanf("%s", s);
            if(!ans) continue;

            Node* cur = &node[0];
            bool isnew = false;
            for(int j = 0, x; s[j]; j++){
                x = s[j] - '0';
                if(!(cur->next[x])) {
                    cur->next[x] = &node[nidx++];
                    isnew = true;
                }
                cur = cur->next[x];
                if(cur->valid) break;
            }
            cur->valid = true;
            ans = isnew;
        }

        printf("%s\n", ans ? "YES" : "NO");
    }

    return 0;
}

