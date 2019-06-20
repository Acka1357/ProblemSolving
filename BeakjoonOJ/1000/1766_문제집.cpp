//
// Created by Acka on 2017. 9. 13..
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> aft[32001];
int in[32001];

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        aft[a].push_back(b);
        in[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= N; i++)
        if(!in[i]) q.push(i);

    while(!q.empty()){
        int cur = q.top(); q.pop();
        printf("%d ", cur);
        for(int i = 0; i < aft[cur].size(); i++)
            if(!(--in[aft[cur][i]])) q.push(aft[cur][i]);
    }
    printf("\n");

    return 0;
}
