//
// Created by Acka on 11/3/16.
//

#include <stdio.h>

#define MAXP    7368791

bool notP[MAXP + 1] = {true, true,};
int nth = 0, nthP[500001], sqi[101], chk[MAXP + 1];

void set_prime(){
    for(int i = 2; i <= MAXP; i++){
        if(notP[i]) continue;
        nthP[nth++] = i;
        for(long long int j = (long long)i * i; j <= MAXP; j += i)
            notP[j] = true;
    }
}

int main()
{
    set_prime();

    for(int i = 2, pi = 0, sq; i <= 100; i++){
        sq = i * i;
        while(nthP[pi] < sq) pi++;
        sqi[i] = pi;
    }

    for(int tc = 1, N, M; scanf("%d %d", &M, &N) == 2; tc++){
        if(!N && !M) return 0;

        int ans = 0;
        for(int i = M, sq = M * M; i < sq; i++)
            if(chk[i] != tc){
                for(int j = i; j <= sq; j += i)
                    chk[j] = tc;
                if(!(N--)){
                    ans = i;
                    break;
                }
            }

        printf("%d\n", ans ? ans : nthP[sqi[M] + N]);
    }
    return 0;
}
