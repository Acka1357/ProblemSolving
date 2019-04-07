//
// Created by Acka on 2017. 5. 23..
//

#include <stdio.h>

#define PRIME_COUNT 1229

bool notP[10001] = {true, true};
int pcnt = 0, p[PRIME_COUNT];

void set_prime(){
    for(int i = 2; i <= 10000; i++){
        if(notP[i]) continue;
        p[pcnt++] = i;
        for(int j = i * i; j <= 10000; j += i)
            notP[j] = true;
    }
}

int main()
{
    set_prime();

    int tc; for(scanf("%d", &tc); tc--;){
        int N; scanf("%d", &N);

        int sm;
        for(int i = 0; i < pcnt; i++){
            if(p[i] * 2 > N) break;
            if(!notP[N - p[i]]) sm = p[i];
        }

        printf("%d %d\n", sm, N - sm);
    }

    return 0;
}
