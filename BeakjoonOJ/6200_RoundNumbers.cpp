#include <cstdio>
#include <cstring>

int d[32][32][2], c[32][32];

int count(int N){
	int l = 0, rev = 0, sum = 0;
	while(N){
		l++;
		rev <<= 1; rev |= N & 1; N >>= 1;
	}

	for(int i = 2; i < l; i++)
		for(int j = i / 2 - 1; j >= 0; j--)
			sum += c[i - 1][j];

	memset(d, 0, sizeof(d));

	d[1][1][0] = 1; rev >>= 1;
	for(int i = 2; i <= l; i++, rev >>= 1){
		int cb = rev & 1;
		for(int j = 1; j < i; j++){
			if(cb){
				d[i][j][1] += d[i - 1][j][0] + d[i - 1][j][1];
				d[i][j + 1][0] += d[i - 1][j][0];
				d[i][j + 1][1] += d[i - 1][j][1];
			}
			else{
				d[i][j][0] += d[i - 1][j][0];
				d[i][j][1] += d[i - 1][j][1];
				d[i][j + 1][1] += d[i - 1][j][1];
			}
		}
	}

	for(int i = l / 2; i > 0; i--)
		sum += d[l][i][0] + d[l][i][1];

	return sum;
}

int main()
{
	for(int i = 0; i < 32; i++)
		for(int j = c[i][0] = 1; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];

	int S, E; scanf("%d %d", &S, &E);
	printf("%d\n", count(E) - count(S - 1));
	
	return 0;
}
