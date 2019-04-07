//
// Created by Acka on 2017. 4. 7..
//

#include <stdio.h>
#include <queue>
using namespace std;

int mind[1000001];

int main()
{
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    queue<int> q;
    q.push(S);
    mind[S] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(G == cur) break;
        if(D < cur){
            if(!mind[cur - D]){
                q.push(cur - D);
                mind[cur - D] = mind[cur] + 1;
            }
        }
        if(cur + U <= F){
            if(!mind[cur + U]){
                q.push(cur + U);
                mind[cur + U] = mind[cur] + 1;
            }
        }
    }

    if(mind[G]) printf("%d\n", mind[G] - 1);
    else printf("use the stairs\n");

    return 0;
}
