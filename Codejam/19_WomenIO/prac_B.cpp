#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Lv{
    int lv;
    ll n;
    bool operator <(const Lv &o)const{
        return lv < o.lv;
    }
};

Lv lv[1001];

int main()
{
    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int L; scanf("%d", &L);
        for(int i = 0; i < L; i++)
            scanf("%lld %d", &lv[i].n, &lv[i].lv);
            
        sort(lv, lv + L);
        
        ll ans = lv[L - 1].lv + 1, child = 0;
        for(int i = 0; i < L; i++)
            child = max(0ll, child - lv[i].n * lv[i].lv) + lv[i].n;
        
        printf("Case #%d: %lld\n", tc, max(ans, child));
    }
    return 0;
}
