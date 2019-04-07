#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, C, D; scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("%d\n", B + D - A - C - (B < C || D < A ? 0 : min(B, D) - max(A, C)));
	return 0;
}