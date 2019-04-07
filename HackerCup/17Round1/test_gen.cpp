/*
//
// Created by Acka on 2017. 1. 15..
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    freopen("/Users/Acka/ClionProjects/ProblemSolving/HackerCup/17Round1/C_test_small.in", "w", stdout);
    printf("100\n");
    int N = 5, M = 10, K = 5;
    for(int tc = 1; tc <= 100; tc++){
        printf("%d %d %d\n", N, M, K);
        for(int i = 0, u, v, c; i < M; i++) {
            u = rand() % N + 1;
            v = rand() % N + 1;
            while(v == u) v = rand() % N + 1;
            c = rand() % 1000 + 1;
            printf("%d %d %d\n", u, v, c);
        }
        for(int i = 0, t, f; i < K; i++){
            t = rand() % N + 1;
            f = rand() % N + 1;
            while(t == f) f = rand() % N + 1;
            printf("%d %d\n", t, f);
        }

    }
    return 0;
}
*/
