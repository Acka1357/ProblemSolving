//
// Created by Acka on 2017. 5. 23..
//

#include <stdio.h>
#include <vector>
using namespace std;

struct Edge{
    int to, cost;
    Edge(){}
    Edge(int t, int c):to(t), cost(c){}
};

int ans;
vector<Edge> adj[10001];

int get_dia(int cur){
    int max1 = 0, max2 = 0;

    for(int i = 0, l; i < adj[cur].size(); i++){
        l = get_dia(adj[cur][i].to) + adj[cur][i].cost;
        if(l > max1){ 
            max2 = max1; max1 = l;
        }
        else if(l > max2) max2 = l;
    }

    if(ans < max1 + max2) ans = max1 + max2;
    return max1;
}

int main()
{
    int N, max = 0; scanf("%d", &N);

    for(int i = 1, f, t, c; i < N; i++){
        scanf("%d %d %d", &f, &t, &c);
        adj[f].push_back(Edge(t, c));
    }

    get_dia(0);
    printf("%d\n", max);
    return 0;
}
