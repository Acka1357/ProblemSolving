#include <stdio.h>
#include <algorithm>
using namespace std;

char s[334];
int R, C, h[334], li[334], minh[334];

int max_lec(){
    int ret = 0, top = 0;
    for(int i = 0; i <= C; i++){
        int mini = i;
        while(top && minh[top] >= h[i]){
            ret = max(ret, (i - li[top]) * minh[top]);
            mini = li[top];
            top--;
        }
        li[++top] = mini;
        minh[top] = h[i];
    }
    return ret;
}

int main()
{
    scanf("%d %d", &R, &C);

    int ans = 0;
    for(int i = 0; i < R; i++){
        scanf("%s", s);
        for(int j = 0; j < C; j++)
            h[j] = (s[j] == '0' ? h[j] + 1 : 0);
        ans = max(ans, max_lec());
    }

    printf("%d\n", ans);
    return 0;
}
