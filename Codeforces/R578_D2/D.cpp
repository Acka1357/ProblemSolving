#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

char map[2003][2003];
int rcnt[2003][2003], ccnt[2003][2003];
int row_l[2003], row_r[2003], col_b[2003], col_t[2003];
int TN, row_l_tree[1 << 12], row_r_tree[1 << 12], col_b_tree[1 << 12], col_t_tree[1 << 12];

void add_val(int *tree, int idx, int val){
	for(idx = TN + idx - 1; idx; idx >>= 1)
		tree[idx] += val;
}

int range_sum(int *tree, int ql, int qr, int idx = 1, int l = 1, int r = TN){
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return tree[idx];
	return range_sum(tree, ql, qr, idx * 2, l, (l + r) / 2)
		   + range_sum(tree, ql, qr, idx * 2 + 1, (l + r) / 2 + 1, r);
}

int main()
{
	int N, K; scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
		scanf("%s", map[i] + 1);

	int B = 0;
	for(TN = 1; TN < N; TN <<= 1);
	for(int i = 1; i <= N; i++){
		row_l[i] = col_b[i] = N + 1; row_r[i] = col_t[i] = 0;
		for(int j = 1; j <= N; j++){
			if(map[i][j] == 'B'){
				row_l[i] = min(row_l[i], j); row_r[i] = max(row_r[i], j);
			}
			if(map[j][i] == 'B'){
				col_b[i] = min(col_b[i], j); col_t[i] = max(col_t[i], j);
			}
		}
		if(!row_r[i]) B++; if(!col_t[i]) B++;
		if(row_r[i] - row_l[i] >= K){
			row_l[i] = N + 1; row_r[i] = 0;
		}
		if(col_t[i] - col_b[i] >= K){
			col_b[i] = N + 1; col_t[i] = 0;
		}
	}

	for(int i = 1; i < K; i++)
		if(row_r[i]){
			add_val(row_l_tree, row_l[i], 1);
			add_val(row_r_tree, row_r[i], 1);
		}
	for(int i = 1; i <= N - K + 1; i++){
		if(row_r[i - 1]){
			add_val(row_l_tree, row_l[i - 1], -1);
			add_val(row_r_tree, row_r[i - 1], -1);
		}
		if(row_r[i + K - 1]){
			add_val(row_l_tree, row_l[i + K - 1], 1);
			add_val(row_r_tree, row_r[i + K - 1], 1);			
		}
		for(int j = 1; j <= N - K + 1; j++)
			rcnt[i][j] = row_l_tree[1] - range_sum(row_l_tree, 1, j - 1) - range_sum(row_r_tree, j + K, N);
	}

	for(int i = 1; i < K; i++)
		if(col_t[i]){
			add_val(col_b_tree, col_b[i], 1);
			add_val(col_t_tree, col_t[i], 1);
		}
	for(int i = 1; i <= N - K + 1; i++){
		if(col_t[i - 1]){
			add_val(col_b_tree, col_b[i - 1], -1);
			add_val(col_t_tree, col_t[i - 1], -1);
		}
		if(col_t[i + K - 1]){
			add_val(col_b_tree, col_b[i + K - 1], 1);
			add_val(col_t_tree, col_t[i + K - 1], 1);			
		}
		for(int j = 1; j <= N - K + 1; j++)
			ccnt[i][j] = col_b_tree[1] - range_sum(col_b_tree, 1, j - 1) - range_sum(col_t_tree, j + K, N);
	}

	int ans = 0;
	for(int i = 1; i <= N - K + 1; i++)
		for(int j = 1; j <= N - K + 1; j++)
			ans = max(ans, rcnt[i][j] + ccnt[j][i]);
	printf("%d\n", B + ans);

	return 0;
}
