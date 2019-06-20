#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MOD     1000000007

int N;
string s[3000];
long long fac[28] = {1, 1,};

long long calc_perm(int idx, int l, int r){
    if(l == r) return 1;

    long long perm = 1, cnt = 0;
    if(s[l].size() == idx){
        cnt = 1; l++;
    }

    for(char ch = 'A'; ch <= 'Z' && l <= r; ch++)
        if(s[l][idx] == ch){
            int nl = l;
            while(l <= r && s[l][idx] == ch) l++;
            perm = (perm * calc_perm(idx + 1, nl, l - 1)) % MOD;
            cnt++;
        }

    return (perm * fac[cnt]) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();

    for(int i = 2; i <= 27; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> s[i];

    sort(s, s + N);

    cout << calc_perm(0, 0, N - 1) << "\n";
    return 0;
}
