#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <memory.h>
#include <string.h>
using namespace std;

long long gcd(long long a, long long b){
	long long c;
	while(b){
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}

bool psb[45001];

int main()
{
	int N; scanf("%d", &N);

	for(int i = 3; i <= N; i++){
		long long sum = ((long long)i * (i - 1)) / 2;
		if(gcd(sum, i) > 1) psb[i] = true;
	}

	for(int i = 3; i <= N; i++)
		if(psb[i] && N % i == 0){
			printf("Yes\n");
			printf("%d ", N / i);
			for(int j = N; j > 0; j -= i)
				printf("%d ", j);
			printf("\n%d ", (N - (N / i)));
			for(int j = 1; j < N; j++)
				if(j % i) printf("%d ", j);
			printf("\n");
			return 0;
		}

	printf("No\n");
	return 0;
}
