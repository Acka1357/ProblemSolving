#include <cstdio>
#include <algorithm>
using namespace std;

const int BASE = 4000;

int N, a[500001], cnt[8001], sum;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		sum += a[i];
		a[i] += BASE;
		cnt[a[i]]++;
	}

	sort(a, a + N);

	int fre = 0, fre_cnt = cnt[0], fre2 = -1, fre2_cnt = -1;
	for(int i = 1; i <= 8000; i++){
		if(cnt[i] > fre_cnt){
			fre_cnt = cnt[i];
			fre = i;
		}
		else if(cnt[i] == fre_cnt){
			if(cnt[i] > fre2_cnt){
				fre2_cnt = cnt[i];
				fre2 = i;
			}
		}
	}

	printf("%.0lf\n%d\n%d\n%d\n", 
		   (double)sum / N, 
		   a[N / 2] - BASE, 
		   (fre_cnt == fre2_cnt ? fre2 : fre) - BASE, 
		   a[N - 1] - a[0]);

	return 0;
}