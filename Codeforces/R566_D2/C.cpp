#include <cstdio>
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
#include <map>
#include <iostream>
using namespace std;

typedef long long ll;

int N, aeiou[256];
char tmp[1000001];
string s[100001];
vector<int> idx[1000001][5], ans;

int main()
{
	aeiou['a'] = 0; aeiou['e'] = 1; aeiou['i'] = 2; aeiou['o'] = 3; aeiou['u'] = 4;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", tmp);
		s[i] = "";
		int len = strlen(tmp), cnt = 0, last = 0;
		for(int j = 0; j < len; j++){
			s[i] += tmp[j];
			if(tmp[j] == 'a' || tmp[j] == 'e' || tmp[j] == 'i' || tmp[j] == 'o' ||tmp[j] == 'u'){
				cnt++; last = aeiou[tmp[j]];
			}
		}
		idx[cnt][last].push_back(i);

	}

	int last_fcnt = 0;
	vector<int> fir, sec;
	for(int i = 1; i <= 1000000; i++)
		for(int j = 0; j < 5; j++){
			int cnt = idx[i][j].size() / 2;
			for(int k = 0; k < cnt; k++){
				sec.push_back(idx[i][j][k * 2]);
				sec.push_back(idx[i][j][k * 2 + 1]);
			}
			if(idx[i][j].size() & 1){
				if(fir.size() % 2 == 1 && last_fcnt != i) fir.pop_back();
				fir.push_back(idx[i][j][idx[i][j].size() - 1]);
				last_fcnt = i;
			}
		}

	int F = fir.size(), S = sec.size(), fi = 0, si = 0;
	while(si < S){
		if(fi + 1 < F){
			ans.push_back(fir[fi++]);
			ans.push_back(fir[fi++]);
			ans.push_back(sec[si++]);
			ans.push_back(sec[si++]);
		}
		else if(si + 3 < S){	
			ans.push_back(sec[si++]);
			ans.push_back(sec[si++]);
			ans.push_back(sec[si++]);
			ans.push_back(sec[si++]);
		}
		else break;
	}

	printf("%d\n", ans.size() / 4);
	for(int i = 0; i < ans.size(); i += 4)
		printf("%s %s\n%s %s\n", s[ans[i]].c_str(), s[ans[i + 2]].c_str(), s[ans[i + 1]].c_str(), s[ans[i + 3]].c_str());
	return 0;
}
