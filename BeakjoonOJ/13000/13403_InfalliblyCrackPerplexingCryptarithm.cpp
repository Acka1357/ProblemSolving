#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

#define B 		0
#define N 		1
#define F 		2
#define T 		3
#define E 		4
#define P_OPEN	2147483647
#define PLUS	2147483646
#define MINUS	2147483645
#define MULT	2147483644

char sign[8] = {'=', '0', '1', '+', '-', '*', '(', ')'};
char org[32], s[32], pick[8], use[8];
bool chk[256], assigned[8], d[32][32][5];
int idx[256], next_i, ans, alpn, slen, st[50], post[50], st_idx, post_idx;

void plus_minus(int OP){
	while(st_idx && (st[st_idx - 1] == MULT || st[st_idx - 1] == PLUS || st[st_idx - 1] == MINUS))
		post[post_idx++] = st[--st_idx];
	st[st_idx++] = OP;
}

int calc_val(int l, int r){
	st_idx = post_idx = 0;
	for(int i = l; i <= r; i++){
		if(s[i] == '(') st[st_idx++] = P_OPEN;
		else if(s[i] == ')'){
			while(st_idx && st[--st_idx] != P_OPEN)
				post[post_idx++] = st[st_idx];
		}
		else if(s[i] == '+') plus_minus(PLUS);
		else if(s[i] == '*') st[st_idx++] = MULT;
		else if(s[i] == '-'){
			int cnt = 1, pchk = (i == l ? 0 : ((s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '*') ? 0 : 1));
			while(i < r && s[i + 1] == '-') cnt++, i++;
			if(cnt & 1){
				if(pchk) plus_minus(MINUS);
				else post[post_idx++] = -1, st[st_idx++] = MULT;
			}
			else if(pchk) plus_minus(PLUS);
		}
		else{
			int v = s[i] - '0';
			while(i < r && (s[i + 1] == '0' || s[i + 1] == '1')){
				v <<= 1;
				v += s[++i] - '0';
			}
			post[post_idx++] = v;
		}
	}
	while(st_idx) post[post_idx++] = st[--st_idx];
	
	for(int i = st_idx = 0; i < post_idx; i++, st_idx--){
		if(post[i] == PLUS) st[st_idx - 2] += st[st_idx - 1];
		else if(post[i] == MINUS) st[st_idx - 2] -= st[st_idx - 1];
		else if(post[i] == MULT) st[st_idx - 2] *= st[st_idx - 1];
		else{ st[st_idx++] = post[i]; st_idx++; }
	}
	return st[0];
}

bool is_valid(int sl, int sr){
	int cnt = 0;
	for(int i = sl; i <= sr; i++){
		if(s[i] == '(') cnt++;
		else if(s[i] == ')'){
			if(--cnt < 0) return false;
		}
	}
	if(cnt) return false;

	memset(d, false, sizeof(d));
	for(int i = sl; i <= sr; i++)
		if(s[i] == '1' || s[i] == '0'){
			for(int j = 0; j < 5; j++) d[i][i][j] = true;
		}

	for(int len = 2; len <= sr - sl + 1; len++)
		for(int l = sl, r = sl + len - 1; r <= sr; l++, r++){
			if(d[l + 1][r][B] && (s[l] == '0'|| s[l] == '1')) d[l][r][B] = true;
			if(d[l + 1][r][B] && s[l] =='1') d[l][r][N] = true;
			if(d[l + 1][r][F] && s[l] == '-') d[l][r][F] = true;
			if(len > 2){
				if(d[l + 1][r - 1][E] && s[l] == '(' && s[r] == ')') d[l][r][F] = true;
				for(int m = l + 1; m < r; m++){
					if(d[l][m - 1][T] && d[m + 1][r][F] && s[m] == '*') d[l][r][T] = true;
					if(d[l][m - 1][E] && d[m + 1][r][T] && (s[m] == '-' || s[m] == '+')) d[l][r][E] = true;
				}
			}
			for(int i = 2; i < 5; i++) d[l][r][i] |= d[l][r][i - 1];
		}
	
	return d[sl][sr][E];
}

void make_perm(){
	for(int i = 0; i < alpn; i++)
		use[i] = pick[i];
	sort(use, use + alpn);

	do{
		int we = -1;
		for(int i = 0; i < slen; i++){
			if(('a' <= org[i] && org[i] <= 'z') || ('A' <= org[i] && org[i] <= 'Z'))
				s[i] = use[idx[org[i]]];
			if(s[i] == '='){
				if(we < 0) we = i;
				else{ we = -1; break; }
			}
		}
		if(we <= 0 && slen - 1 <= we) continue;
		if(is_valid(0, we - 1) && is_valid(we + 1, slen - 1)) 
			ans += (calc_val(0, we - 1) == calc_val(we + 1, slen - 1));
	}while(next_permutation(use, use + alpn));
}

void pick_n(int sign_i, int pick_cnt){
	if(pick_cnt == alpn){
		make_perm();
		return ;
	}
	if(sign_i == 8) return ;
	pick_n(sign_i + 1, pick_cnt);
	pick[pick_cnt] = sign[sign_i];
	pick_n(sign_i + 1, pick_cnt + 1);
}

int main()
{
	scanf("%s", org);
	slen = strlen(org);
	for(int i = 0; i < slen; i++) s[i] = org[i];
	for(int i = 0; i < slen; i++)
		if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
			if(!chk[s[i]]) chk[s[i]] = true, idx[s[i]] = next_i++;
		}
	alpn = next_i;
	if(alpn > 8) return !printf("0\n");
	pick_n(0, 0);
	printf("%d\n", ans);
	return 0;
}
