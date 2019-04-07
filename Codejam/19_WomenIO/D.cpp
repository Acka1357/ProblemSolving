#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <random>
#include <set>
using namespace std;

typedef long long ll;

char my[6], rb[6], top[6], low[6];

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);

void set_rand(char* w){
	for(int i = 0; i < 5; i++)
    	w[i] = 'A' + (dis(gen) % 10);
}

ll s_to_i(char* s){
	ll hash = 0;
	for(int i = 0; s[i]; i++)
		hash = hash * 10 + s[i] - 'A';
	return hash;
}

void i_to_s(ll hash, char* s){
	for(int i = 4; i >= 0; i--){
		s[i] = 'A' + (hash % 10);
		hash /= 10;
	}
}

ll concat(char* s1, char* s2){
	return s_to_i(s1) * 100000 + s_to_i(s2);
}

void split(ll hash, char* s1, char* s2){
	i_to_s(hash / 100000, s1);
	i_to_s(hash % 100000, s2);
}

void set_win(char* cur, char* past){
	if(strcmp(past, low) == 0){
		do { 
			set_rand(cur); 
		} while(!strcmp(cur, top) || !strcmp(cur, low));
	}
	else if(strcmp(past, top) == 0) strcpy(cur, low);
	else strcpy(cur, top);
}

int main()
{	
	int T, N, tc = 0; for(scanf("%d %d", &T, &N); tc++ < T;){
		bool chk = false, chk_tmp = false;
	    set<long long> mset;
	    set_rand(my); 
	    printf("%s\n", my); 
	    fflush(stdout);
		for(int i = 0; i < 100; i++){
			scanf("%s", rb); 
			if(!chk){
				ll hash = concat(my, rb);
				if(mset.count(hash)){
					strcpy(top, my);
					strcpy(low, rb);
					chk_tmp = true;
				}
				else if(chk_tmp) chk = true;
				else mset.insert(hash);
				strcpy(my, rb);
			}
			if(chk) set_win(my, rb);
			printf("%s\n", my);
			fflush(stdout);
		}
    }
	return 0;
}
