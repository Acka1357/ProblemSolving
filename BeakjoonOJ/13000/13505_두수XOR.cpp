//
// Created by Acka on 10/27/16.
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
    int N, x; scanf("%d %d", &N, &x);

    int ans = 0;
    Trie trie(30); trie.add_node(x);
    while(--N){
        scanf("%d", &x);
        ans = max(ans, x ^ trie.get_max_rev(x));
        trie.add_node(x);
    }

    printf("%d\n", ans);
    return 0;
}
