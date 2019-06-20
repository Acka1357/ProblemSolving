//
// Created by Acka on 2017. 8. 22..
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Sq{
    int w, h, d;
    Sq(){}
    Sq(int w, int h):w(w), h(h), d(w * w + h * h){}
    bool operator <(const Sq &A)const{
        return d == A.d ? h < A.h : d < A.d;
    }
};

Sq sq[150 * 151];

int main()
{
    int cnt = 0;
    for(int i = 1; i <= 150; i++)
        for(int j = i + 1; j <= 150; j++)
            sq[cnt++] = Sq(j, i);
    sort(sq, sq + cnt);

    for(int w, h; scanf("%d %d", &h, &w) == 2;){
        if(w + h == 0) break;
        for(int i = 0; i < cnt; i++)
            if(sq[i].w == w && sq[i].h == h){
                printf("%d %d\n", sq[i + 1].h, sq[i + 1].w);
                break;
            }
    }
    return 0;
}