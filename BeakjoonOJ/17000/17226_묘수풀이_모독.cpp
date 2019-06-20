/*
	2019 Ajou Univ. Programming Contest
	묘수풀이: 모독 - 서브태스크2
	Acka's cpp solution
	Time Complexity: O((N + M) * (M + 1)^N)
*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct Unit{
	int atk, hp, idx;
	bool operator <(const Unit &o)const{
		return atk < o.atk;
	} 
};

int N, M, my_hp[7], en_hp[7], atk[7], cnt[13];
Unit my[7], en[7];

bool find_gak(int ni){
	if(ni == N){
		int cnt[13] = {0,};
		for(int i = 0; i < N; i++)
			if(my_hp[i] > 0) cnt[my_hp[i]]++;
		for(int i = 0; i < M; i++)
			if(en_hp[i] > 0) cnt[en_hp[i]]++;

		int dead = 1;
		while(dead < 12 && cnt[dead]) dead++;
		for(int i = 0; i < M; i++)
			if(en_hp[i] > dead) return false;

		int log_cnt = 1;
		for(int i = 0; i < N; i++)
			log_cnt += atk[i] >= 0;
		printf("%d\n", log_cnt);
		for(int i = 0; i < N; i++)
			if(atk[i] >= 0) printf("attack %d %d\n", my[i].idx, atk[i] + 1);
		printf("use modok\n");

		return true;
	}

	for(int i = 0; i < M; i++)
		if(en_hp[i] > 0){
			atk[ni] = i;
			my_hp[ni] -= en[i].atk;
			en_hp[i] -= my[ni].atk;
			if(find_gak(ni + 1)) return true;
			my_hp[ni] += en[i].atk;
			en_hp[i] += my[ni].atk;
		}

	atk[ni] = -1;
	return find_gak(ni + 1);
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){
		scanf("%d %d", &my[i].atk, &my[i].hp);
		my[i].idx = i + 1;
		cnt[my_hp[i]]++;
	}

	sort(my, my + N);
	
	for(int i = 0; i < N; i++)
		my_hp[i] = my[i].hp;

	for(int i = 0; i < M; i++){
		scanf("%d %d", &en[i].atk, &en[i].hp);
		en_hp[i] = en[i].hp;
		cnt[en_hp[i]]++;
	}

	if(!find_gak(0)) printf("-1\n");

	return 0;
}
