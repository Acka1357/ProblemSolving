#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

string map[500001];
int rcnt[500001], ccnt[500001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while(T--){
		int R, C; cin >> R >> C;
		memset(rcnt, 0, (R + 1) * sizeof(rcnt[0]));
		memset(ccnt, 0, (C + 1) * sizeof(ccnt[0]));
		for(int i = 0; i < R; i++){
			cin >> map[i];
			for(int j = 0; j < C; j++){
				if(map[i][j] == '*')
					rcnt[i]++, ccnt[j]++;
			}
		}

		int ans = R + C - 1;
		if(R == 1) ans = C - rcnt[0];
		else if(C == 1) ans = R - ccnt[0];
		else{
			for(int i = 0; i < R; i++)
				for(int j = 0; j < C; j++)
					ans = min(ans, R + C - rcnt[i] - ccnt[j] - (map[i][j] != '*'));
		}
		printf("%d\n", ans);
	}
	return 0;
}
