#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

struct Info{
	int who, has;
	Info(){} Info(int w, int h): who(w), has(h){}
	bool operator <(const Info &o)const{
		return has == o.has ? who < o.who : has < o.has;
	}
};

string tmp;
vector<Info> inp;
char line[2000002], s[2000002], *buf;
int nidx, widx, slen;
vector<string> str;
map<string, int> name, word;

struct Ans{
	int i, cnt;
	Ans(int i, int c):i(i), cnt(c){}
	bool operator <(const Ans &o)const{
		return cnt == o.cnt ? str[i] < str[o.i] : cnt > o.cnt;
	}
};

vector<Ans> ans;

int main()
{	
	ios::sync_with_stdio(false);

	int N; scanf("%d ", &N);
	while(N--){
		fgets(line, 2000001, stdin);
		sscanf(line, "%s", s);
		tmp = string(s);
		if(!name.count(tmp)) name[tmp] = nidx++;
		int who = name[tmp];
		buf = line + strlen(s) + 1;
		while('a' <= buf[0] && buf[0] <= 'z'){
			slen = 0;
			while('a' <= buf[0] && buf[0] <= 'z'){
				s[slen++] = buf[0];
				buf++;
			}
			s[slen] = 0; buf++;
			tmp = string(s);
			if(!word.count(tmp)){
				word[tmp] = widx++;
				str.push_back(tmp);
			}
			inp.push_back(Info(who, word[tmp]));
		}
	}

	sort(inp.begin(), inp.end());

	for(int i = 0; i < inp.size();){
		bool psb = !inp[i].who;
		int cnt = 1, hasi = inp[i++].has;
		while(i < inp.size() && inp[i].has == hasi){
			if(inp[i].who - inp[i - 1].who > 1) psb = false;
			cnt++; i++;
		}
		if(inp[i - 1].who != nidx - 1) psb = false;
		if(psb) ans.push_back(Ans(hasi, cnt));
	}

	sort(ans.begin(), ans.end());

	if(ans.empty()){
		cout << "ALL CLEAR\n";
	}
	else{
		for(int i = 0; i < ans.size(); i++)
			cout << str[ans[i].i] << "\n";
	}

	return 0;
}
