//
// Created by Acka on 10/26/16.
//

#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Data{
    int a, b;
    Data(){} Data(int a, int b):a(a), b(b){};
};

queue<Data> q;
char d[40001][40001];
char ans[20001];

int main()
{
    memset(d, 0xff, sizeof(d));
    memset(ans, 0xff, sizeof(ans));
    ans[0] = ans[1] = d[1][0] = 0;


    q.push(Data(1, 0));
    while(!q.empty()){
        int a = q.front().a, b = q.front().b; q.pop();
        if(a <= 20000){
            if(ans[a] < 0) ans[a] = d[a][b];
        }
        if(b <= 20000) {
            if (ans[b] < 0) ans[b] = d[a][b];
        }

        if(a + b <= 40000){
            if(d[a + b][b] < 0){
                q.push(Data(a + b, b));
                d[a + b][b] = d[a][b] + 1;
            }
            if(d[a][a + b] < 0){
                q.push(Data(a, a + b));
                d[a][a + b] = d[a][b] + 1;
            }
        }
        if(a + a <= 40000){
            if(d[a + a][b] < 0){
                q.push(Data(a + a, b));
                d[a + a][b] = d[a][b] + 1;
            }
            if(d[a][a + a] < 0){
                q.push(Data(a, a + a));
                d[a][a + a] = d[a][b] + 1;
            }
        }
        if(b + b <= 40000){
            if(d[b + b][b] < 0){
                q.push(Data(b + b, b));
                d[b + b][b] = d[a][b] + 1;
            }
            if(d[a][b + b] < 0){
                q.push(Data(a, b + b));
                d[a][b + b] = d[a][b] + 1;
            }
        }
        if(b < a){
            if(d[a - b][b] < 0){
                q.push(Data(a - b, b));
                d[a - b][b] = d[a][b] + 1;
            }
            if(d[a][a - b] < 0){
                q.push(Data(a, a - b));
                d[a][a - b] = d[a][b] + 1;
            }
        }
        if(a < b){
            if(d[a][b - a] < 0){
                q.push(Data(a, b - a));
                d[a][b - a] = d[a][b] + 1;
            }
            if(d[b - a][b] < 0){
                q.push(Data(b - a, b));
                d[b - a][b] = d[a][b] + 1;
            }
        }
        if(d[0][b] < 0){
            q.push(Data(0, b));
            d[0][b] = d[a][b] + 1;
        }
        if(d[a][0] < 0){
            q.push(Data(a, 0));
            d[a][0] = d[a][b] + 1;
        }
    }

    freopen("/Users/acka/ClionProjects/ProblemSolving/2074.txt", "w", stdout);
    for(int i = 0; i <= 20000; i++)
        printf("%d,", (int)ans[i]);

    return 0;
}
