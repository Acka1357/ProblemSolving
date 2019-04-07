//
// Created by Acka on 10/28/16.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node{
    Node *next[2];
    Node(){
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
        }
    }

    int get_max_rev(int x){
        Node* cur = &root;
        int rev = 0;
        for(int b = max_bit, nb; b; b >>= 1){
            nb = x & b ? 1 : 0;

            if(cur->next[1 - nb]){
                if(1 - nb) rev += b;
                cur = cur->next[1 - nb];
            }
            else {
                if(nb) rev += b;
                cur = cur->next[nb];
            }
        }
        return rev;
    }
};

int main()
{
    int tc; for(scanf("%d", &tc); tc--;) {
        int N; scanf("%d", &N);

        Trie trie(31); trie.add_node(0);
        int ans = 0, acc = 0, x;
        while (N--) {
            scanf("%d", &x);
            acc ^= x;
            ans = max(ans, acc ^ trie.get_max_rev(acc));
            trie.add_node(acc);
        }

        printf("%d\n", ans);
    }
    return 0;
}

