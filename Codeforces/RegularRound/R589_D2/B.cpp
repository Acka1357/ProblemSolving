#include <cstdio>

typedef long long ll;

const ll mod = 1000000007;

int map[1003][1003];

int main()
{
	int R, C, x; scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++){
		scanf("%d", &x);
		for(int j = 0; j < x; j++)
			map[i][j] = 1;
		map[i][x] = -1;
	}
	for(int i = 0; i < C; i++){
		scanf("%d", &x);
		for(int j = 0; j < x; j++){
			if(map[j][i] == -1)
				return !printf("0\n");
			map[j][i] = 1;
		}
		if(map[x][i] == 1) return !printf("0\n");
		map[x][i] = -1;
	}

	ll ans = 1;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(!map[i][j]) ans = (ans * 2) % mod;
	printf("%lld\n", ans);

	return 0;
}