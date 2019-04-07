#include <cstdio>
#include <algorithm>
using namespace std;

int dis(int a, int b){
    return (a - b) * (a - b);
}

int real[101], ideal[101];

int main()
{
    int T, tc = 0; for(scanf("%d", &T); tc++ < T;){
        int K; scanf("%d", &K);
        for(int i = 0; i < K; i++)
            scanf("%d", &ideal[i]);
        for(int i = (K - 1) / 2; i >= 0; i--)
            real[i] = real[K - i - 1] = i;
            
        sort(ideal, ideal + K);
        
        int ans = 0;
        for(int i = 0; i < K; i++)
            ans += dis(real[i], ideal[i]);
        
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
