#include <stdio.h>
#include <math.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef complex<double> base;
 
void fft(vector<base> &a, bool invert)
{
    int n = a.size();
    for (int i = 1,j = 0; i < n; i++){
        int bit = n >> 1;
        for(; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len = 2; len <= n; len <<= 1){
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len){
            base w(1);
            for (int j = 0; j < len / 2; j++){
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}
 
void multiply(const vector<long long> &a, const vector<long long> &b, vector<long long> &res)
{
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    for(int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    res.resize(n);
    for (int i = 0; i < n; i++) 
        res[i] = fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5);
}

int main()
{
    long long N, L, M, W; scanf("%lld %lld %lld %lld", &N, &L, &M, &W);

    vector<long long> a(N * M), b(L * M);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &a[j * M + i]);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < L; j++)
            scanf("%d", &b[L * M - (j * M + i) - 1]);

    vector<long long> res(N * M);
    multiply(a, b, res);

    int ans = 0;
    for(int i = L * M - 1; i < N * M; i += M)
        ans += (res[i] > W);

    printf("%d\n", ans);
    return 0;
}

