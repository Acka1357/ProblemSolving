//
// Created by Acka on 5/6/16.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

struct Node{
    int p;
    vector<int> c;
};

Node node[250001];
int lp[250001], rp[250001];
bool del[250001];
int N, M, P, ni = 1;

void set_lp(int p){
    if(!node[p].c.size()) return ;

    lp[node[p].c[0]] = -1;
    for(int i = 1, sz = node[p].c.size(); i < sz; i++){
        lp[node[p].c[i]] = node[p].c[i - 1];
    }

    for(int i = node[p].c.size() - 1; 0 <= i; i--)
        set_lp(node[p].c[i]);
}

void set_rp(int p){
    if(!node[p].c.size()) return ;

    rp[node[p].c[node[p].c.size() - 1]] = -1;
    for(int i = 0, sz = node[p].c.size() - 1; i < sz; i++){
        rp[node[p].c[i]] = node[p].c[i + 1];
    }

    for(int i = node[p].c.size() - 1; 0 <= i; i--)
        set_rp(node[p].c[i]);
}

bool set_start_node(int p, int* pp, int* ppp){
    if(p) {
        if (!(--P)) {
            *pp = p;
            *ppp = 0;
            return true;
        }
    }

    for(int i = 0, sz = node[p].c.size(); i < sz; i++)
        if(set_start_node(node[p].c[i], pp, ppp)) return true;

    if(p) {
        if (!(--P)) {
            *pp = p;
            *ppp = 1;
            return true;
        }
    }

    return false;
}

int find_lp(int x){
    if(lp[x] < 0) return -1;
    return del[lp[x]] ? (lp[x] = find_lp(lp[x])) : lp[x];
}

int find_rp(int x){
    if(rp[x] < 0) return -1;
    return del[rp[x]] ? (rp[x] = find_rp(rp[x])) : rp[x];
}

void print_node(int p){
    if(p) printf("(");
    for(int i = 0, sz = node[p].c.size(); i < sz; i++)
        if(!del[node[p].c[i]]) print_node(node[p].c[i]);
    if(p) printf(")");
}

int main()
{
    char s[500001], cmd[500001];
    scanf("%d %d %d %s %s", &N, &M, &P, s, cmd);

    node[0].p = -1;
    int p = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == '('){
            node[p].c.push_back(ni);
            node[ni].p = p;
            p = ni++;
        }
        else {
            p = node[p].p;
        }
    }

    set_lp(0); set_rp(0);

    int pp = 0, ppp = 0;
    set_start_node(0, &pp, &ppp);

    int ret;
    bool psb;
    for(int i = 0; i < M; i++){
        if(cmd[i] == 'R'){
            if(ppp == 0){
                psb = node[pp].c.size();
                if(psb){
                    if(del[node[pp].c[0]])
                        ret = find_rp(node[pp].c[0]);
                    else ret = node[pp].c[0];

                    if(ret < 0) psb = false;
                    else pp = ret;
                }
                if(!psb) ppp = 1;
            }
            else {
                ret = find_rp(pp);
                if(ret < 0) pp = node[pp].p;
                else {
                    pp = ret; ppp = 0;
                }
            }
        }
        else if(cmd[i] == 'L'){
            if(ppp == 0){
                ret = find_lp(pp);
                if(ret < 0) pp = node[pp].p;
                else {
                    pp = ret; ppp = 1;
                }
            }
            else {
                psb = node[pp].c.size();
                if(psb){
                    if(del[node[pp].c[node[pp].c.size() - 1]])
                        ret = find_lp(node[pp].c[node[pp].c.size() - 1]);
                    else ret = node[pp].c[node[pp].c.size() - 1];

                    if(ret < 0) psb = false;
                    else pp = ret;
                }
                if(!psb) ppp = 0;
            }
        }
        else{
            del[pp] = true;
            if(node[pp].p){
                pp = node[pp].p;
                ppp = 1;
            }
            else{
                ret = find_rp(pp);
                if(ret < 0){
                    pp = find_lp(pp);
                    ppp = 1;
                }
                else{
                    pp = ret;
                    ppp = 0;
                }
            }
        }
    }

    print_node(0);
    printf("\n");
    return 0;
}
