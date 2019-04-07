//
// Created by Acka on 2017. 7. 28..
//

#include <stdio.h>

#define BUCKET_SIZE 100007

void strcpy(char *dest, char *src){
    int i;
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = src[i];
}

bool is_same(char *a, char *b, int len){
    for (int i = 0; i < len; i++)
        if (a[i] != b[i]) return false;
    return true;
}

struct ListNode{
    char s[101];
    int count;
    ListNode* next;
    ListNode(){
        next = NULL;
    }
};

struct List{
    ListNode *head, *tail;

    List(){
        head = new ListNode();
        tail = head;
    }

    void clear(){
        if(head->next) delete_node(head->next);
        tail = head;
        tail->next = NULL;
    }

    void delete_node(ListNode *cur){
        if(cur->next != NULL) delete_node(cur->next);
        delete cur;
    }

    void add(char *s){
        ListNode *new_node = new ListNode();
        strcpy(new_node->s, s);
        new_node->count = 1;
        tail->next = new_node;
        tail = new_node;
    }
};

struct HashSet{
    List bucket[BUCKET_SIZE];

    void init(){
        for(int i = 0; i < BUCKET_SIZE; i++)
            bucket[i].clear();
    }

    void add(char *x, int len, int hash_value){
        ListNode *cur = bucket[hash_value].head;
        while (cur->next != NULL){
            cur = cur->next;
            if (is_same(cur->s, x, len)) return;
        }
        bucket[hash_value].add(x);
    }

    int count(char *x, int len, int hash_value){
        ListNode *cur = bucket[hash_value].head;
        while (cur->next != NULL){
            cur = cur->next;
            if (is_same(cur->s, x, len)) return 1;
        }
        return 0;
    }
};

HashSet hash;

bool determine(int l, char* s){
    hash.init();

    int hash_value = 0;
    for (int i = 0; i < l; i++)
        hash_value = (hash_value * 27 + s[i] - 'a' + 1) % BUCKET_SIZE;
    hash.add(s, l, hash_value);

    int digit = 1;
    for (int i = 1; i < l; i++) digit = (digit * 27) % BUCKET_SIZE;

    for (int i = l; s[i]; i++){
        hash_value -= ((s[i - l] - 'a' + 1) * digit) % BUCKET_SIZE;
        hash_value = (hash_value + BUCKET_SIZE) % BUCKET_SIZE;
        hash_value = ((hash_value * 27 + s[i] - 'a' + 1) % BUCKET_SIZE);
        if (hash.count(s + i - l + 1, l, hash_value)) return true;
        else hash.add(s + i -  l + 1, l, hash_value);
    }

    return false;
}

char s[200001];

int main()
{
    int L; scanf("%d %s", &L, s);

    int l = 1, r = L, m, ans = 0;
    while (l <= r){
        m = (l + r) / 2;
        if (determine(m, s)){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    printf("%d\n", ans);
    return 0;
}
