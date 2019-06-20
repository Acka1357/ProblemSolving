#include <cstdio>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <memory.h>
using namespace std;

const int K = 10;
const double err = 1e-4;

double coef[K + 1];

int main(int argc, char* argv[])
{
	for(int tc = 0; tc < 66; tc++){
        char in[256] = "/Users/acka/Downloads/integrate/", out[256] = "/Users/acka/Downloads/integrate/";
        strcat(in, fname[tc]); strcat(out, fname[tc]);
        strcat(in, ".in"); strcat(out, ".out");

        FILE* fin = fopen(in, "r");
        FILE* fuser = fopen(out, "r");

    	int k;
		fscanf(fin, "%d", &k);
		for (int i = k; i >= 0; i--)
		{
			fscanf(fin, "%lf", &coef[i]);
		}
		int a, b, n;
		fscanf(fin, "%d%d%d", &a, &b, &n);
		double d = 1.0 * (b - a) / n;
		
		double e;
		fscanf(fuser, "%lf", &e);
		double sum = 0.0;
		for (int i = 0; i < d; i++)
		{
			double x = a + d * i + e;
			double xn = 1.0;
			for (int j = 0; j <= k; j++)
			{
				sum += coef[j] * xn;
				xn *= x;
			}
		}

		double area = 0.0, an = a, bn = b;
		for (int i = 0; i <= k; i++)
		{
			area += coef[i] * (bn - an) / (i + 1);
			an *= a;
			bn *= b;
		}

		// if(abs(sum - area) / max(1.0, area) > err){
			printf("%s\n", fname[tc]);
			printf("real: %.10lf\nuser: %.10lf\nerror: %.16lf\n", area, sum, abs(sum - area) / max(1.0, area));
		// }
	}
	return 0;
}

