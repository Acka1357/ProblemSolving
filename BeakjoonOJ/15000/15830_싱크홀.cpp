#include <cstdio>

typedef long double ld;

int main()
{
	ld V, W, D; scanf("%Lf %Lf %Lf", &V, &W, &D);
	int cnt = 0;
	while(5 * (W / V) * (W / V) < D){
		cnt++;
		D -= 5 * (W / V) * (W / V);
		W *= 1.25;
	}
	printf("%d\n", cnt);

	return 0;
}