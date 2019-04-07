#include <stdio.h>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;

const double eps = 1e-12;

long long N, K, a[100001];

long long find_k(double a, double lb){
	return (-1 + sqrt(1 + 4 * a / lb)) / 2 + 1; 
}

int main()
{
	scanf("%lld %lld", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%lld", &a[i]);

	sort(a, a + N, greater<int>());

	double l = 0, r = 1e12, m, ans = -1;
	while(r - l > eps){
		m = (l + r) / 2;
		long long sum = 0;
		for(int i = 0; i < N && sum <= K; i++)
			sum += find_k(a[i], m);
		if(sum <= K) ans = m, r = m - eps;
		else l = m + eps;
	}
	
	double sumt = 0;
	long long rem = K, tmp;
	for(int i = 0; i < N; i++){
		tmp = find_k(a[i], ans);
		rem -= tmp;
		sumt += (double)a[i] / tmp;
	}

	printf("%.0lf\n", sumt - rem * ans);
	return 0;
}