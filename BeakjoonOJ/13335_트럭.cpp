//
// Created by Acka on 2017. 1. 19..
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Truck{
    int t, w;
    Truck(){}
    Truck(int t, int w):t(t), w(w){}
};

int main()
{
    int N, W, L; scanf("%d %d %d", &N, &L, &W);

    int w[1000], t = 0;
    for(int i = 0; i < N; i++)
        scanf("%d", &w[i]);

    queue<Truck> q;
    for(int i = 0, sum = 0; i < N; i++, t++){
        while(!q.empty()){
            if(W < sum + w[i] || q.front().t + L <= t) {
                t = q.front().t + L;
                sum -= q.front().w;
                q.pop();
            }
            else break;
        }

        sum += w[i];
        q.push(Truck(t, w[i]));
    }

    printf("%d\n", t + L);
    return 0;
}

