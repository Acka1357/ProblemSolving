#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Info{
	string name; int t; bool in;
	bool operator <(const Info &o)const{
		return name == o.name ? t < o.t : name > o.name;
	}
};

Info a[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for(int i = 0; i < N; i++){
		string tag;
		cin >> a[i].name >> tag;
		a[i].in = (tag[0] == 'e');
		a[i].t = i;
	}

	sort(a, a + N);

	for(int i = 0; i < N - 1; i ++)
		if(a[i].name != a[i + 1].name && a[i].in)
			cout << a[i].name << "\n";
	if(a[N - 1].in) cout << a[N - 1].name << "\n";

	return 0;
}