#include <cstdio>
#include <vector>
using namespace std;

struct Info{
	int nth, cnt;
	Info(): nth(0), cnt(0){} Info(int nth, int cnt): nth(nth), cnt(cnt){}
	bool operator == (const Info &o)const{
		return nth == o.nth && cnt == o.cnt;
	}
	bool operator != (const Info &o)const{
		return nth != o.nth || cnt != o.cnt;
	}
};

int N, P, S, n[100001], p[25001], ncum[100001][25], pcum[25001][25], f[25001];
Info pth[25001], pwh[25001];

void pre(int L, int a[], int cum[][25]){
	for(int i = 1; i <= L; i++){
		scanf("%d", &a[i]);
		for(int j = 0; j < S; j++)
			cum[i][j] = cum[i - 1][j];
		cum[i][--a[i]]++;
	}
}

Info order(int cum[][25], int l, int r, int x){
	Info ret;
	for(int i = 0; i < S; i++)
		if(cum[r][i] > cum[l - 1][i]){
			ret.cnt++;
			if(i < x) ret.nth++;
		}
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &P, &S);
	pre(N, n, ncum);
	pre(P, p, pcum);

	for(int i = 1; i <= P; i++){
		pth[i] = order(pcum, 1, i, p[i]);
		pwh[i] = order(pcum, 1, P, p[i]);
	}

	for(int i = 2, j = 0; i <= P; i++){
		while(j && order(pcum, i - j, i, p[i]) != pth[j + 1])
			j = f[j];
		if(order(pcum, i - j, i, p[i]) == pth[j + 1]) f[i] = ++j;
	}

	vector<int> ans;
	for(int i = 1, j = 0; i <= N; i++){
		if(i + P - j - 1 > N) break;
		while(j && (order(ncum, i - j, i + P - j - 1, n[i]) != pwh[j + 1] || order(ncum, i - j, i, n[i]) != pth[j + 1]))
			j = f[j];
		if(order(ncum, i - j, i + P - j - 1, n[i]) == pwh[j + 1] && order(ncum, i - j, i, n[i]) == pth[j + 1]){
			if(++j == P) ans.push_back(i - P + 1), j = f[j];
		}
	}

	printf("%lu\n", ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);

	return 0;
}
