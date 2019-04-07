//
// Created by Acka on 2017. 8. 21..
//

#include <stdio.h>
#include <deque>
using namespace std;

int arr[5000001];

int main()
{
    int N, L; scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    deque<int> q;
    for(int i = 0; i < N; i++){
        if(!q.empty() && q.front() <= i - L) q.pop_front();
        while(!q.empty()){
            if(arr[q.back()] >= arr[i]) q.pop_back();
            else break;
        }
        q.push_back(i);
        printf("%d ", arr[q.front()]);
    }

    printf("\n");
    return 0;
}

