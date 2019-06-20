// solution:
// {{An, An-1}} = {{x, y}, {1, 0}}^(n-1) * {{a1}, {a0}}
// 위 행렬연산을 100에 대한 나머지로 기록하며 계산한다.

// 시간복잡도: O(logN)
// 난이도: 1250-1500
// 분류: Matrix Multiplication, DP

#include <cstdio>

void mult_mat(int a[][2], int b[][2], int c[][2]){
	int tmp[2][2];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			tmp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			c[i][j] = tmp[i][j] % 100;
}

int main()
{
	int p[2][2] = {{0, 0}, {1, 0}}, a0, a1, n, m[2][2] = {{1, 0}, {0, 1}};
	scanf("%d %d %d %d %d", &p[0][0], &p[0][1], &a0, &a1, &n);
	if(!n) return printf("%02d\n", a0);
	for(n--; n; n >>= 1){
		if(n & 1) mult_mat(m, p, m);
		mult_mat(p, p, p);
	}
	printf("%02d\n", (m[0][0] * a1 + m[0][1] * a0) % 100);

	return 0;
}