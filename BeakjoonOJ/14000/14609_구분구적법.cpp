#include <stdio.h>
#include <string.h>

double c[11];

int main()
{
    int K; scanf("%d", &K);
    for(int i = K; i >= 0; i--)
        scanf("%lf", &c[i]);

    double A, B, N; scanf("%lf %lf %lf", &A, &B, &N);
    double area = 0, x = 1, a = A, b = B;
    for(int i = 0; i <= K; i++){
        area += c[i] * (b - a) / (i + 1);
        a *= A, b *= B;
    }

    int cnt = 100000;
    double l = 0, r = (B - A) / N, m;
    while(cnt--){
        m = (l + r) / 2;
        double sum = 0;
        for(int i = 0; i < N; i++){
            double x = A + i * (B - A) / N + m, xx = 1;
            for(int j = 0; j <= K; j++){
                sum += ((B - A) / N) * (c[j] * xx);
                xx *= x;
            }
        }
        if(sum < area) l = m;
        else r = m;
    }

    printf("%.10lf\n", l);
    return 0;
}
