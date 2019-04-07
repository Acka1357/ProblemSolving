//
// Created by Acka on 2017. 7. 15..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

long long get_gcd(long long a, long long b){
    long long temp;
    while(b){
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long long get_lcm(long long a, long long b){
    return a * b / get_gcd(a, b);
}

struct Runner{
    long long s, l, d, st, addt;

    void calc_t(){
        st = -1;
        for(int i = 1; i <= s; i++)
            if((l * i + l - d) % s == 0){
                st = (l * i + l - d) / s;
                break;
            }
        addt = l / get_gcd(l, s);
    }

    bool operator <(const Runner &A)const{
        return addt == A.addt ? st > A.st : addt > A.addt;
    }
};

Runner p[5];

int main()
{
    setbuf(stdout, NULL);

    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N; scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%lld %lld %lld", &p[i].s, &p[i].l, &p[i].d);
            p[i].calc_t();
        }

        sort(p, p + N);
        long long t = p[0].st, term = p[0].addt;
        for(int i = 1; i < N; i++){
            while(true){
                if((p[i].s * t - p[i].l + p[i].d) % p[i].l == 0)
                    break;
                t += term;
            }
            term = get_lcm(term, p[i].addt);
        }

        printf("Case #%d\n%lld\n", tc, t);
    }
    return 0;
}

