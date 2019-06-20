//
// Created by Acka on 2017. 8. 22..
//

#include <stdio.h>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> crd[3000];

int main()
{
    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        set<pair<long long, long long>> st;
        for(int i = 0; i < N; i++){
            scanf("%lld %lld", &crd[i].first, &crd[i].second);
            st.insert(crd[i]);
        }

        long long ans = 0, x1, y1, x2, y2, xx1, yy1, xx2, yy2;
        for(int i = 0; i < N; i++){
            x1 = crd[i].first; y1 = crd[i].second;
            for(int j = i + 1; j < N; j++){
                x2 = crd[j].first, y2 = crd[j].second;
                xx1 = x1 + x2 - y1 + y2;
                xx2 = x1 + x2 + y1 - y2;
                yy1 = y1 + y2 + x1 - x2;
                yy2 = y1 + y2 - x1 + x2;
                if(xx1 & 1 || xx2 & 1 || yy1 & 1 || yy2 & 1) continue;
                if(st.find(make_pair(xx1 / 2, yy1 / 2)) != st.end() &&
                        st.find(make_pair(xx2 / 2, yy2 / 2)) != st.end())
                    ans = max(ans, (x1 - xx1 / 2) * (x1 - xx1 / 2) + (y1 - yy1 / 2) * (y1 - yy1 / 2));
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}

