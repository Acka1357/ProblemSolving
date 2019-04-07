//
// Created by Acka on 10/28/16.
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

    int get_rev_count(int x, int K){
        Node* cur = &root;
        long long int ret = 0;
        for(int b = max_bit, h = height - 1, nb, nk, n; b; b >>= 1, h--){
            nb = x & b ? 1 : 0;
            nk = K & b ? 1 : 0;

            if(nk){
                if(cur->next[nb]) ret += cur->next[nb]->subsum;
                n = 1 - nb;
            }
            else n = nb;

            if(cur->next[n]) cur = cur->next[n];
            else break;
        }
        return ret;
    }
};

int main()
{
    int N, K; scanf("%d %d", &N, &K);

    Trie trie(21); trie.add_node(0);
    long long int ans = 0;
    int acc = 0;
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);

        acc ^= x;
        ans += trie.get_rev_count(acc, K);
        trie.add_node(acc);
    }

    printf("%lld\n", ans);
    return 0;
}
