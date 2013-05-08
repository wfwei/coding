#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int n,bit;
	double sum,ans;
	while(scanf("%d",&n)!=EOF&&n)
	{
	    sum = (double)( 1.0*(n+2)*(n+1)*n/6.0);
	    bit = (int)log10(sum);
	    ans = sum / pow(10.0, (1.0*bit));
	    printf("%0.2lfE%d\n", ans, bit);
	}
}
