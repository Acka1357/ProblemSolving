//
// Created by Acka on 2017. 4. 30..
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
    int tc = 5;
    printf("%d\n", tc);

    while(tc--)
    {
        int n = rand() % 1001;
        int k = rand() % n;
        printf("%d %d", n, k);

        for(int i = 0; i < n; i++)
            printf("%d %d", rand()%1000001, rand())
    }
    return 0;
}
