#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int L, ansl;
char s[200002], ans[200002];

bool is_smaller(char *a, char *b){
	for(int i = ansl - 1; i >= 0; i++)
		if(a[i] != b[i]) return a[i] < b[i];
	return false;
}

void calc(int mid){
	char sum[200002] = {0, };
	for(int i = 0; i <= mid; i++)
		sum[mid - i] += s[i] - '0';
	for(int i = L - 1, j = 0; i > mid; i--, j++)
		sum[j] += s[i] - '0';

	int l = max(mid + 1, L - mid - 1);
	for(int i = 0; i < l; i++){
		if(sum[i] > 9){
			sum[i] -= 10;
			sum[i + 1]++;
		}
		sum[i] += '0';
	}

	if(sum[l]) sum[l++] = '1';
	
	printf("%d: %s\n", mid, sum);

	if(ansl < l) return;
	if(l < ansl || is_smaller(sum, ans)){
		for(int i = 0; i < l; i++)
			ans[i] = sum[i];
		ansl = l;
		ans[l] = 0;
	}
}

int main()
{
	scanf("%d %s", &L, s);

	ansl = L;
	for(int i = 0; i < L; i++)
		ans[L - i - 1] = s[i];

	int mid = L / 2 - 1;
	for(int i = mid, cnt = 2; i >= 0 && cnt; i--)
		if(s[i + 1] != '0'){
			calc(i); cnt--;
		}
	for(int i = mid + 1, cnt = 2; i < L - 1 && cnt; i++)
		if(s[i + 1] != '0'){
			calc(i); cnt--;
		}

	for(int i = ansl - 1; i >= 0; i--)
		printf("%c", ans[i]);
	printf("\n");

	return 0;
}
