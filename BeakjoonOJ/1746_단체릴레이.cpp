// solution:
// 실제 정점 개수가 200개 이하이므로 이를 압축하여
// d[i][j]: 정확히 n개의 정점을 지나 i에서 j로 가는 최단거리
// 위를 행렬연산으로 정의하고 빠른 행렬곱으로 해결할 수 있다.
// 옛날 유사코라 1억 넘는 복잡도가 정해일 것 같지는 않지만 일단 풀었는데,
// 놀랍게도 출제진 솔루션은 행렬연산(...) 다익스트라 변형으로 푼 사람이 더 많았다.

// 시간복잡도: O(T^3 * logN)
// 분류: ShortestPath, Divide&Conquer
// 난이도: 1750 ~ 2000

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

int N, T, S, E, d[100], u[100], v[100], mat[200][200], pmat[200][200];

void mult_mat(int a[][200], int b[][200], int res[][200]){
	int tmp[200][200];
	for(int i = 0; i < T; i++)
		for(int j = 0; j < T; j++){
			tmp[i][j] = 0x3f3f3f3f;
			for(int k = 0; k < T; k++)
				if(a[i][k] >= 0 && b[k][j] >= 0)
					tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
		}
	for(int i = 0; i < T; i++)
		for(int j = 0; j < T; j++)
			res[i][j] = tmp[i][j];
}

int main()
{
	scanf("%d %d %d %d", &N, &T, &S, &E);
	vector<int> uv(2 * T);
	for(int i = 0; i < T; i++){
		scanf("%d %d %d", &d[i], &u[i], &v[i]);
		uv[i * 2] = u[i]; uv[i * 2 + 1] = v[i];
	}

	sort(uv.begin(), uv.end());
	uv.erase(unique(uv.begin(), uv.end()), uv.end());

	map<int, int> mp;
	for(int i = 0; i < uv.size(); i++)
		mp[uv[i]] = i;

	S = mp[S], E = mp[E];
	memset(mat, 0xff, sizeof(mat));
	memset(pmat, 0xff, sizeof(pmat));
	for(int i = 0; i < T; i++){
		u[i] = mp[u[i]], v[i] = mp[v[i]];
		mat[u[i]][v[i]] = mat[v[i]][u[i]] = pmat[u[i]][v[i]] = pmat[v[i]][u[i]] = d[i];
	}
	
	T = uv.size();
	for(N--; N; N >>= 1){
		if(N & 1) mult_mat(mat, pmat, mat);
		mult_mat(pmat, pmat, pmat);
	}
	printf("%d\n", mat[S][E]);

	return 0;
}