#include <cstdio>
#include <algorithm>
using namespace std;

int a[5003];

int paint(int l, int r, int h){
	int minh = a[l], chk = 0;
	for(int i = l; i <= r; i++){
		if(a[i] == a[l]) chk++;
		minh = min(minh, a[i]);
	}

	if(chk == r - l + 1) 
		return min(minh - h, r - l + 1);

	int cnt = minh - h, pl = l;
	for(int i = l; i <= r; i++){
		if(a[pl] == minh) pl = i;
		else if(a[i] == minh){
			cnt += paint(pl, i - 1, minh);
			pl = i;
		}
	}
	if(a[pl] != minh && a[r] != minh)
		cnt += paint(pl, r, minh);

	return min(cnt, r - l + 1);
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	printf("%d\n", min(N, paint(0, N - 1, 0)));
	return 0;
}