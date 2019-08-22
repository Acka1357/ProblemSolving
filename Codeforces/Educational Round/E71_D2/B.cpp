#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[55][55], b[55][55];

int main()
{
	int R, C; scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			scanf("%d", &a[i][j]);

	vector<int> ansr, ansc;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			bool chk = true;
			for(int di = 0; di < 2; di++)
				for(int dj = 0; dj < 2; dj++)
					if(a[i + di][j + dj] != 1) chk = false;
			if(chk){
				for(int di = 0; di < 2; di++)
					for(int dj = 0; dj < 2; dj++)
						b[i + di][j + dj] = 1;
				ansr.push_back(i); ansc.push_back(j);
			}
		}

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(a[i][j] != b[i][j]) return !printf("-1\n");

	printf("%d\n", ansr.size());
	for(int i = 0; i < ansr.size(); i++)
		printf("%d %d\n", ansr[i] + 1, ansc[i] + 1);

	return 0;
}