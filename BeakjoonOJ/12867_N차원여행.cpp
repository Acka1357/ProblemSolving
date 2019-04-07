//
// Created by Acka on 7/4/16.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N, M; scanf("%d %d", &N, &M);

    map<int, int> idx;
    int d[50], cnt = 0;
    for(int i = 0; i < M; i++) {
        scanf("%d", &d[i]);
        if(!idx.count(d[i])) idx[d[i]] = cnt++;
    }

    char c[51]; scanf("%s", c);

    set<vector<int> > s;
    vector<int> v(cnt);
    s.insert(v);

    bool psb = true;
    for(int i = 0; i < M; i++){
        v[idx[d[i]]] += (c[i] == '+' ? 1 : -1);
        if(s.count(v)){
            psb = false; break;
        }
        s.insert(v);
    }

    printf("%d\n", psb ? 1 : 0);
    return 0;
}

