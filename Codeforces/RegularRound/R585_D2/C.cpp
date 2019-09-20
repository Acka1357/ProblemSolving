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
using namespace std;

typedef long long ll;

char a[200005], b[200005];
queue<int> ab, ba;
vector<int> ansa, ansb;

int main()
{
	int L, acnt = 0, bcnt = 0; scanf("%d %s %s", &L, a, b);
	for(int i = 0; i < L; i++){
		if(a[i] == 'a' && b[i] == 'b') ab.push(i), acnt++, bcnt++;
		else if(a[i] == 'b' && b[i] == 'a') ba.push(i), acnt++, bcnt++;
		else if(a[i] == 'a' && b[i] == 'a') acnt += 2;
		else bcnt += 2;
	}

	if((acnt & 1) + (bcnt & 1)) 
		return !printf("-1\n");

	if(ab.size() & 1){
		ansa.push_back(ab.front());
		ansb.push_back(ab.front());
		ba.push(ab.front()); ab.pop();
	}
	if(ba.size() & 1){
		ansa.push_back(ba.front());
		ansb.push_back(ba.front());
		ab.push(ba.front()); ba.pop();
	}

	while(ab.size() > 1){
		ansa.push_back(ab.front()); ab.pop();
		ansb.push_back(ab.front()); ab.pop();
	}
	while(ba.size() > 1){
		ansa.push_back(ba.front()); ba.pop();
		ansb.push_back(ba.front()); ba.pop();
	}

	if(!ab.empty() || !ba.empty())
		return !printf("-1\n");

	printf("%d\n", ansa.size());
	for(int i = 0; i < ansa.size(); i++)
		printf("%d %d\n", ansa[i] + 1, ansb[i] + 1);

	return 0;
}