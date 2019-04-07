#include <stdio.h>
#include <algorithm>
using namespace std;

bool notmy[100001];
int e1[25000], e2[25000];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N / 2; i++){
		scanf("%d", &e1[i]);
		notmy[e1[i]] = true;
	}
	for(int i = 0; i < N / 2; i++){
		scanf("%d", &e2[i]);
		notmy[e2[i]] = true;
	}

	sort(e1, e1 + N / 2);
	sort(e2, e2 + N / 2);

	int ans = 0;
	for(int i = 2 * N, j = N / 2 - 1; i && j >= 0; i--){
		if(notmy[i]) continue;
		if(e1[j] < i) ans++, notmy[i] = true, j--;
		else i++, j--;
	}
	for(int i = 1, j = 0; j < N / 2 && i <= 2 * N; i++){
		if(notmy[i]) continue;
		if(i < e2[j]) ans++, j++;
		else i--, j++;
	}

	printf("%d\n", ans);
	return 0;
}