#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Col{ 
	int amax;
	vector<int> a;
	bool operator <(const Col &o)const{
		return amax > o.amax;
	}
};

Col cols[2001];
int d[13][1 << 12], td[1 << 12], b[12];

int main()
{
	for(int i = b[0] = 1; i < 12; i++)
		b[i] = (b[i - 1] << 1);

	int tc; for(scanf("%d", &tc); tc--;){
		int R, C; scanf("%d %d", &R, &C);
		for(int i = 0; i < C; i++)
			cols[i].amax = 0, cols[i].a.clear();
		for(int i = 0, x; i < R; i++)
			for(int j = 0; j < C; j++){
				scanf("%d", &x);
				cols[j].a.push_back(x);
				cols[j].amax = max(cols[j].amax, x);
			}

		memset(d[min(R, C)], 0, sizeof(d[0]));
		sort(cols, cols + C);

		int L = (1 << R);
		for(int i = min(R, C) - 1; i >= 0; i--){
			vector<int> &a = cols[i].a;
			
			for(int st = 0; st < L; st++)
				d[i][st] = d[i + 1][st];

			for(int p = 0; p < R; p++){
				int tmp = a[0];
				for(int j = 1; j < R; j++)
					a[j - 1] = a[j];
				a[R - 1] = tmp;

				for(int st = 0; st < L; st++) 
					td[st] = d[i + 1][st];
				
				for(int st = 1; st < L; st++){
					for(int j = 0; j < R; j++){
						if(!(st & b[j])) continue;
						td[st] = max(td[st], td[st ^ b[j]] + a[j]);
					}
				}
				for(int st = 0; st < L; st++)
					d[i][st] = max(d[i][st], td[st]);
			}
		}
		printf("%d\n", d[0][L - 1]);
	}
	return 0;
}