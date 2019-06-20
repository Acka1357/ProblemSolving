//
// Created by Acka on 2017. 10. 31..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MOD     1000000000

bool notp[34000] = {true, true, };
int p[3638], pcnt = 0, cnt1[3638], cnt2[3638], p1[1000], p2[1000], pcnt1, pcnt2;

void set_prime(){
    for(int i = 2; i < 34000; i++){
        if(notp[i]) continue;
        p[pcnt++] = i;
        for(int j = i * i; j < 34000; j += i)
            notp[j] = true;
    }
}

void fact(int *resf, int *resp, int &pi){
    int N; scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        for(int j = 0; j < pcnt && x > 1; j++){
            while(!(x % p[j])){
                resf[j]++;
                x /= p[j];
            }
        }
        if(x > 1) resp[pi++] = x;
    }
}

int main()
{
    set_prime();
    fact(cnt1, p1, pcnt1);
    fact(cnt2, p2, pcnt2);

    bool chk = false;
    long long ans = 1;
    for(int i = 0; i < pcnt; i++)
        for(int j = (cnt1[i] < cnt2[i] ? cnt1[i] : cnt2[i]); j; j--){
            ans *= p[i];
            if(ans >= MOD) chk = true, ans %= MOD;
        }

    sort(p1, p1 + pcnt1);
    sort(p2, p2 + pcnt2);
    for(int i = 0, j = 0; i < pcnt1 && j < pcnt2;){
        if(p1[i] < p2[j]) i++;
        else if(p1[i] > p2[j]) j++;
        else{
            ans *= p1[i];
            i++, j++;
            if(ans >= MOD) chk = true, ans %= MOD;
        }
    }

    if(chk) printf("%09lld\n", ans);
    else printf("%lld\n", ans);
    return 0;
}

