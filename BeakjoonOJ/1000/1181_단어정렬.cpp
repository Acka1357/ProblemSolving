//
// Created by Acka on 2017. 4. 17..
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct String{
    char s[51];
    int len;

    bool operator <(const String &o)const{
        if(len == o.len){
            return strcmp(s, o.s) < 0;
        }
        return len < o.len;
    }
};

bool cmp(String A, String B){
    if(A.len == B.len){
        return strcmp(A.s, B.s) < 0;
    }
    return A.len < B.len;
}

String arr[20000];

int main()
{
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", arr[i].s);
        arr[i].len = strlen(arr[i].s);
    }

    sort(arr, arr + N);

    printf("%s\n", arr[0].s);
    for(int i = 1; i < N; i++)
        if(strcmp(arr[i].s, arr[i - 1].s) != 0)
            printf("%s\n", arr[i].s);

    return 0;
}

