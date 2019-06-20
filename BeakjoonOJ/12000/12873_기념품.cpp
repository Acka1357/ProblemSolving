//
// Created by Acka on 7/5/16.
//

#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    queue<int> q;
    for(int i = 1; i <= N; i++)
        q.push(i);

    for(int i = 1; i < N; i++){
        int d = (((long long)i * i * i - 1) % q.size());
        while(d--){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    printf("%d\n", q.front());
    return 0;
}
