//
// Created by Acka on 7/12/16.
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int get_count(int w, int target){
    int cnt = 0;
    while(target < w){
        w = (w + 1) / 2;
        cnt++;
    }
    return cnt;
}

int main()
{
    int W, H, A; scanf("%d %d %d", &W, &H, &A);

    vector<pair<int, int> > div;
    for(int i = 1; i * i <= A; i++){
        if(A % i) continue;
        if(i * i == A) div.push_back(make_pair(i, i));
        else div.push_back(make_pair(i, A / i));
    }

    int ans = 987654321;
    for(int i = 0; i < div.size(); i++){
        if(div[i].first <= W && div[i].second <= H)
            ans = min(ans, get_count(W, div[i].first) + get_count(H, div[i].second));
        if(div[i].second <= W && div[i].first <= H)
            ans = min(ans, get_count(W, div[i].second) + get_count(H, div[i].first));
    }

    printf("%d\n", ans < 987654321 ? ans : -1);
    return 0;
}
