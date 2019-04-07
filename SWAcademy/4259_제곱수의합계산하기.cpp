#include <stdio.h>

struct BigInt{
	char n[50];
	int len;

	BigInt(){
		for(int i = 0; i < 50; i++) n[i] = 0;
		len = 0;
	}
	
	BitInt(int num){
		if(num == 0) n[0] = '0', len = 1;
		for(len = 0; num; len++, num /= 10)
			n[len] = num % 10;
		for(int i = len / 2; i < len; i++){
			char tmp = n[i];
			n[i] = n[len - i - 1];
			n[len - i - 1] = tmp;
		}
		n[len] = 0;
	}

	BigInt operator + (const BigInt &o)const{
		BigInt sum;
		return sum;
	}
	
	BigInt operator * (const BitInt &o)const{

	}
};

void add_mult_value(char* val, int mult, char* to){
	int len = strlen(val);

	for (int i = 0; i < len; i++){
		if (!to[i]) to[i] = '0';
		to[i] += (val[i] - '0') * mult;
	}

	len = strlen(to); to[len] += '0';
	for (int i = 0; i <= len; i++)
		if (to[i] > '9'){
			to[i + 1] += (to[i] - '0') / 10;
			to[i] = (to[i] - '0') % 10 + '0';
		}
	
	if (to[len + 1]) to[len + 1] += '0';
	else if (to[len] == '0') to[len] = 0;
}

long long pow(long long a, long long p){
	if(p <= 1) return a ? a : 1;
	long long sq = pow(a, p / 2);
	return sq * sq * (p & 1 ? a : 1);
}

void solve(){
	int N; scanf("%d", &N);
	char ans[50] = {0,}, a[5], p[2] = {0,};
	for(int i = 0; i < N; i++){
		scanf("%s", a);
		p[0] = a[strlen(a) - 1];
		a[strlen(a) - 1] = 0;
		add_value(ans, pow_value(a, p, , ans)
	}
}

int main()
{
	int T; scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
		solve();

	return 0;
}