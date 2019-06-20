// solution:
// 쿼리가 많이 들어올 때 소인수분해를 빠르게 해야한다.
// 전처리로 에라토스테네스의 체를 쓸 때, 각 숫자가 어떤 소인수를 가지는지 기록해두고
// 소인수분해를 할 때 해당 소인수를 나누고 그 소인수를 나눈 수로 옮겨가는 것을 반복한다.

// 분류: Prime, Eratosthenes Sieve

#include <cstdio>

int pp[5000001];

int main()
{
	for(long long i = 2; i <= 5000000; i++){
		if(pp[i]) continue;
		pp[i] = i;
		for(long long j = i * i; j <= 5000000; j += i)
			if(!pp[j]) pp[j] = i;
	}

	int N, x; for(scanf("%d", &N); N--;){
		scanf("%d", &x);
		while(x > 1){
			printf("%d ", pp[x]);
			x /= pp[x];
		}
		printf("\n");
	}
	return 0;
}