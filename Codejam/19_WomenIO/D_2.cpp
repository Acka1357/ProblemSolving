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

char my[6], rb[6], w1[6], w2[6], w3[6], w4[6], top[6], low[6];

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

int main()
{	
	int T, N, tc = 0; for(scanf("%d %d", &T, &N); tc++ < T;){
		bool chk = false, chk_tmp = false;
	    set_rand(my);
	    set<long long> mset;
		for(int i = 0; i <= 100; i++){
			if(chk){
				if(strcmp(rb, low) == 0){
					do {
						set_rand(my);
					} while(!strcmp(my, top) || !strcmp(my, low));
				}
				else if(strcmp(rb, top) == 0) strcpy(my, low);
				else strcpy(my, top);
				printf("%s\n", my);
				fflush(stdout);
				if(i != 100){
					scanf("%s", rb);
				}
				continue;
			}

			printf("%s\n", my);
			fflush(stdout);
			scanf("%s", rb);
			ll hash = concat(my, rb);
			if(mset.count(hash)){
				split(hash, top, low);
				// strcpy(top, my);
				// strcpy(low, rb);
				chk_tmp = true;
			}
			else if(chk_tmp) chk = true;
			else mset.insert(hash);
			strcpy(my, rb);
		}
    }
	return 0;
}
