#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool chk[500000];
string a[500000], b[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 0; i < M; i++)
		cin >> b[i];

	sort(a, a + N); sort(b, b + M);

	int ans = 0, ai = 0, bi = 0;
	while(ai < N && bi < M){
		if(a[ai] < b[bi]) ai++;
		else if(a[ai] > b[bi]) bi++;
		else{
			chk[ai] = true;
			ans++; ai++; bi++;
		}
	}

	cout << ans << "\n";
	for(int i = 0; i < N; i++)
		if(chk[i]) cout << a[i] << "\n";

	return 0;
}