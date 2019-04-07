//
// Created by Acka on 10/16/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node{
    int subsum;
    Node *next[2];
    Node():subsum(0){
        next[0] = next[1] = NULL;
    }
};

int n[131072];
long long int cnt[31][2];

struct Trie{
    int height, max_bit;
    Node root;
    Trie(int h):height(h), max_bit(1 << (h - 1)){}

    void add_node(int x){
        Node* cur = &root;
        for(int b = max_bit, nb; b; b >>= 1){
            nb = x & b ? 1 : 0;
            if(!(cur->next[nb])) cur->next[nb] = new Node();
            cur = cur->next[nb];
            cur->subsum++;

        }
    }

    void add_rev_count(int x){
        Node* cur = &root;
        for(int b = max_bit, h = height - 1, nb; b; b >>= 1, h--){
            nb = x & b ? 1 : 0;
            if(cur->next[1 - nb])
                cnt[h][nb] += cur->next[1 - nb]->subsum;
            cur = cur->next[nb];
        }
    }
};

int main()
{
    int N, M; scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
        scanf("%d", &n[i]);

    int digit = -1;
    for(; N; digit++, N >>= 1);

    Trie trie(digit);
    for(int i = 0; i < M; i++){
        trie.add_node(n[i]);
        trie.add_rev_count(n[i]);
    }

    long long int ans = 0;
    for(int i = 0; i < digit; i++)
        ans += max(cnt[i][0], cnt[i][1]);

    printf("%lld\n", ans);
    return 0;
}
