#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

char cmd[1000000][10];
int cmdn[1000000];

int main()
{
    int N; scanf("%d", &N);

    priority_queue<int, vector<int>, greater<int> > q;
    char in[10]; int n, idx = 0;
    for(int i = 0; i < N; i++){
        scanf("%s", in);

        if(in[0] != 'r'){
            scanf("%d", &n);
            //insert
            if(in[0] == 'i'){
                q.push(n);
            }
            // getMin
            else{
                while(!q.empty()){
                    if(n <= q.top()) break;
                    strcpy(cmd[idx], "removeMin");
                    idx++;
                    q.pop();
                }

                if(q.empty()){
                    strcpy(cmd[idx], "insert");
                    cmdn[idx++] = n;
                    q.push(n);
                }
                else if(n < q.top()){
                    strcpy(cmd[idx], "insert");
                    cmdn[idx++] = n;
                    q.push(n);
                }
            }
        }
        // removeMin
        else{
            if(q.empty()){
                strcpy(cmd[idx], "insert");
                cmdn[idx++] = 0;
            }
            q.pop();
        }

        strcpy(cmd[idx], in);
        if(in[0] != 'r') cmdn[idx++] = n;
        else idx++;
    }

    printf("%d\n", idx);
    for(int i = 0; i < idx; i++){
        if(cmd[i][0] == 'r') printf("%s\n", cmd[i]);
        else printf("%s %d\n", cmd[i], cmdn[i]);
    }
    return 0;
}

