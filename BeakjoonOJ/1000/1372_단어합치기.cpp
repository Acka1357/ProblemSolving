//
// Created by Acka on 2017. 7. 14..
//

#include <stdio.h>
#include <string.h>
#include <memory.h>

bool sub[12];
char s[12][51], ds[12][1 << 12][12 * 50 + 1], temp[12 * 50 + 1];
int d[12][1 << 12], bit[12], ff[12][51], len[12];

int get_pi(char* p, int* pi){
    for(int i = 1, j = 0; p[i]; i++){
        while(j && p[i] != p[j]) j = pi[j - 1];
        pi[i] = (p[i] == p[j] ? ++j : 0);
    }
}

int max_match(char* str, char* p, int* pi, bool subflag){
    int j = 0;
    for(int i = 0; str[i]; i++){
        while(j && str[i] != p[j]) j = pi[j - 1];
        if(str[i] == p[j]){
            if(!p[++j] && subflag) return j;
        }
    }
    return j;
}

int main()
{
    memset(d, 0x3f, sizeof(d));
    memset(ds, 'Z', sizeof(ds));

    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", s[i]);
        len[i] = strlen(s[i]);
        get_pi(s[i], ff[i]);
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(!strcmp(s[i], s[j])) sub[i > j ? i : j] = true;
            else if(max_match(s[i], s[j], ff[j], true) == len[j])
                sub[j] = true;
        }

    int scnt = 0;
    for(int i = 0; i < N; i++)
        if(!sub[i]) strcpy(s[scnt++], s[i]);

    N = scnt;
    for(int i = 0; i < N; i++){
        len[i] = strlen(s[i]);
        get_pi(s[i], ff[i]);
        bit[i] = 1 << i;
        d[i][bit[i]] = len[i];
        strcpy(ds[i][bit[i]], s[i]);
    }

    int all = (1 << N) - 1;
    for(int used = 1; used <= all; used++)
        for(int last = 0; last < N; last++){
            if(!(used & bit[last])) continue;
            for(int next = 0; next < N; next++){
                if(used & bit[next]) continue;
                int i = max_match(ds[last][used], s[next], ff[next], false);
                int newl = d[last][used] + len[next] - i;
                int nextu = used | bit[next];
                if(d[next][nextu] >= newl){
                    strcpy(temp, ds[last][used]);
                    for(int j = d[last][used]; s[next][i]; i++, j++)
                        temp[j] = s[next][i];
                    temp[newl] = '\0';
                    if(!(d[next][nextu] == newl && strcmp(ds[next][nextu], temp) < 0))
                        strcpy(ds[next][nextu], temp);
                    d[next][nextu] = newl;
                }
            }
        }

    int ans = 12 * 50;
    char ans_s[12 * 50 + 1];
    memset(ans_s, 'Z', sizeof(ans_s));
    for(int i = 0; i < N; i++)
        if(ans >= d[i][all]){
            if(!(ans == d[i][all] && strcmp(ans_s, ds[i][all]) < 0))
                strcpy(ans_s, ds[i][all]);
            ans = d[i][all];
        }

    printf("%s\n", ans_s);
    return 0;
}
