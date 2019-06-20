#include <stdio.h>

int R, C, K, W, map[302][302], ans[302][302], tree[1 << 18], NN;

void add_val(int idx, int val){
	for(idx += NN; idx; idx >>= 1)
		tree[idx] += val;
}

int find_kth(int idx = 1, int l = 0, int r = NN - 1, int k = (W * W) / 2 + 1){
	if(l == r) return l;
	if(tree[idx * 2] >= k) return find_kth(idx * 2, l, (l + r) / 2, k);
	else return find_kth(idx * 2 + 1, (l + r) / 2 + 1, r, k - tree[idx * 2]);
}

int main()
{
	scanf("%d %d %d %d", &R, &C, &K, &W);
	for(NN = 1; NN <= K; NN <<= 1);
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			scanf("%d", &map[i][j]);

	tree[NN] = W;
	for(int i = 1; i < W; i++)
		for(int j = 1; j <= W; j++)
			tree[NN + map[i][j]]++;
	for(int i = NN - 1; i; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];

	int rcnt = R - W + 1, ccnt = C - W + 1;
	for(int i = 1; i <= rcnt; i++){
		if(i & 1){
			for(int j = 1; j <= W; j++){
				add_val(map[i - 1][j], -1);
				add_val(map[i + W - 1][j], 1);
			}
			ans[i][1] = find_kth();
			for(int j = 2; j <= ccnt; j++){
				for(int k = 1; k <= W; k++){
					add_val(map[i + k - 1][j - 1], -1);
					add_val(map[i + k - 1][j + W - 1], 1);
				}
				ans[i][j] = find_kth();
			}
		}
		else{
			for(int j = C - W + 1; j <= C; j++){
				add_val(map[i - 1][j], - 1);
				add_val(map[i + W - 1][j], 1);
			}
			ans[i][ccnt] = find_kth();
			for(int j = ccnt - 1; j >= 1; j--){
				for(int k = 1; k <= W; k++){
					add_val(map[i + k - 1][j + W], -1);
					add_val(map[i + k - 1][j], 1);
				}
				ans[i][j] = find_kth();
			}
		}
	}

	for(int i = 1; i <= rcnt; i++){
		for(int j = 1; j <= ccnt; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}