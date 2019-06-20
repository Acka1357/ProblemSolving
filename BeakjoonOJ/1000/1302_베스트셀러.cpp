//
// Created by Acka on 4/18/16.
//

#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N; scanf("%d", &N);

    string s[1000];
    for(int i = 0; i < N; i++)
        cin >> s[i];

    sort(s, s + N);

    string ans = s[0];
    int ans_cnt = 1, cnt = 1;
    for(int i = 1; i < N; i++){
        if(s[i] == s[i - 1]) cnt++;
        else cnt = 1;
        if(ans_cnt < cnt) {
            ans_cnt = cnt;
            ans = s[i];
        }
        else if(ans_cnt == cnt && s[i] < ans) ans = s[i];
    }

    cout << ans << endl;
    return 0;
}
