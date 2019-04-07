//
// Created by Acka on 2017. 4. 7..
//

#include <stdio.h>
#include <queue>
using namespace std;

struct Info{
    int wnd, clip;
    Info(){}
    Info(int w, int c):wnd(w), clip(c){}
};

int mind[2000][2000];

int main()
{
    int S; scanf("%d", &S);

    queue<Info> q;
    q.push(Info(1, 0));
    mind[1][0] = 1;
    int ans = -1;
    while(!q.empty()){
        int w = q.front().wnd, c = q.front().clip; q.pop();
        if(w == S){
            ans = mind[w][c] - 1;
            break;
        }

        if(!mind[w][w]){
            q.push(Info(w, w));
            mind[w][w] = mind[w][c] + 1;
        }
        if(w + c < 2000){
            if(!mind[w + c][c]){
                q.push(Info(w + c, c));
                mind[w + c][c] = mind[w][c] + 1;
            }
        }
        if(w){
            if(!mind[w - 1][c]){
                q.push(Info(w - 1, c));
                mind[w - 1][c] = mind[w][c] + 1;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
