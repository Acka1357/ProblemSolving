#include <cstdio>
#include <set>
using namespace std;

int x[200], y[200];

int main()
{
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &x[i], &y[i]);

	set<double> st;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
			st.insert(x[i] - x[j] ? ((double)y[i] - y[j]) / (x[i] - x[j]) : 100000000);

	printf("%d\n", st.size());

	return 0;
}