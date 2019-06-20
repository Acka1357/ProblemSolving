#include <stdio.h>
#include <algorithm>
using namespace std;

struct Line{
    int l, r;
    Line(){}
    Line(int l, int r):l(l), r(r){}
    bool operator < (const Line &A)const{
        return r == A.r ? l > A.l : r < A.r;
    }
};

Line line[300000];
Line st[300001];

int main()
{
    // freopen("/Users/Acka/ClionProjects/ProblemSolving/10000_onepoint.in", "r", stdin);
    int N; scanf("%d", &N);
    for(int i = 0, x, r; i < N; i++){
        scanf("%d %d", &x, &r);
        line[i].l = x - r, line[i].r = x + r;
    }

    sort(line, line + N);

    int ans = N, top = 0;
    st[top].l = st[top].r = -1e9 - 1;
    for(int i = 0; i < N; i++){
        if(st[top].l <= line[i].l && line[i].r <= st[top].r) ans++;
        st[++top] = line[i];
        while((st[top - 1].l <= st[top].l && st[top].r <= st[top - 1].r) ||
                (st[top].l <= st[top - 1].r)){
            st[top - 1] = Line(min(st[top - 1].l, st[top].l), st[top].r);
            top--;
        }
    }

    printf("%d\n", ans + 1);
    return 0;
}