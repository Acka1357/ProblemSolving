//
// Created by Acka on 9/30/16.
//

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Vec{
    long long int x, y;
    double ang;
    bool operator <(const Vec &A)const{
        return ang < A.ang;
    }
};

vector<Vec> vec;

long long int get_size(long long int x, long long int y){
    return x * x + y * y;
}

int main()
{
    int N; scanf("%d", &N);

    vec.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%lld %lld", &vec[i].x, &vec[i].y);
        vec[i].ang = atan2(vec[i].y, vec[i].x);
        if(vec[i].ang < 0.0) vec[i].ang += 2.0 * M_PI;
    }

    sort(vec.begin(), vec.end());

    long long int x = 0, y = 0, ans = 0;
    for(int l = 0, r = 0; l < N; l++) {
        while ((get_size(x, y) <= get_size(x + vec[r % N].x, y + vec[r % N].y)) || vec[r % N].x * vec[(r + 1) % N].y == vec[r % N].y * vec[(r + 1) % N].x) {
            if (r < l + N) {
                x += vec[r % N].x;
                y += vec[r % N].y;
                r++;
            }
            else break;
        }

        ans = max(ans, get_size(x, y));
        x -= vec[l % N].x;
        y -= vec[l % N].y;
    }

    printf("%lld\n", ans);
    return 0;
}

