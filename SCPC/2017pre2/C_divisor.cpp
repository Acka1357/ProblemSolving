//
// Created by Acka on 2017. 7. 15..
//

#include <stdio.h>

bool nop[1001] = {true, true, false,};
int a[100000], p[168], pcnt;

void set_prime(){
    for(int i = 2; i <= 1000; i++){
        if(nop[i]) continue;
        p[pcnt++] = i;
        for(int j = i * i; j <= 1000; j += i)
            nop[j] = true;
    }
}

int fact[8], fcnt[8], flen, div[129] = {1,}, dlen;

void factorize(int n){
    flen = 0;
    for(int i = 0; i < pcnt && n > 1; i++)
        if(n % p[i] == 0){
            fact[flen] = p[i];
            fcnt[flen] = 0;
            while(n % p[i] == 0){
                n /= p[i];
                fcnt[flen]++;
            }
            flen++;
        }
    if(n != 1){
        fact[flen] = n;
        fcnt[flen++] = 1;
    }
}

void set_divisor(int n){
    factorize(n);
    dlen = 1;
    for(int i = 0; i < flen; i++)
        for(int j = dlen - 1; j >= 0; j--)
            for(int k = 0, pow = fact[i]; k < fcnt[i]; k++, pow *= fact[i])
                div[dlen++] = div[j] * pow;
}

int main()
{
    setbuf(stdout, NULL);

    set_prime();
    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int N, M; scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);

        int ans = 0;
        while(M--){
            int b, l, r; scanf("%d %d %d", &b, &l, &r);

            set_divisor(b);
            for(int i = 0; i < dlen; i++){
                bool chk = false;
                for(int j = l - 1; j < r; j++)
                    if(a[j] % div[i] == 0){
                        chk = true; break;
                    }
                if(!chk) ans++;
            }
        }

        printf("Case #%d\n%d\n", tc, ans);
    }
    return 0;
}

