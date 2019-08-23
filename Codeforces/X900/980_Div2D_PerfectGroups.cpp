#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int H = 10000;

bool np[10004], chk[5005];
int a[5005], ans[5005];
vector<int> sq, as;

int main()
{
	for(int i = 2; i <= H; i++){
		if(np[i]) continue;
		sq.push_back(i * i);
		for(int j = i * i; j <= H; j += i)
			np[j] = true;
	}

	int N, A = 0; scanf("%d", &N);
	map<int, int> aidx; aidx[0] = A++;
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		if(a[i]){
			for(int &p : sq){
				while(a[i] % p == 0) a[i] /= p;
			}
		}
		if(aidx.count(a[i])) a[i] = aidx[a[i]];
		else a[i] = (aidx[a[i]] = A++);
	}

	for(int i = 0 ; i < N; i++){
		int cnt = 0;
		memset(chk, false, A * sizeof(chk[0]));
		for(int j = i; j < N; j++){
			if(a[j] && !chk[a[j]]) cnt++, chk[a[j]] = true;
			ans[max(1, cnt)]++;
		}
	}

	for(int i = 1; i <= N; i++)
		printf("%d%c", ans[i], " \n"[i == N]);

	return 0;
}