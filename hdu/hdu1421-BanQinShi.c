#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){

    int i, j, n, k, tmp, MAX=1265535;
    int weight[2001], dp[12][2001];

    while(scanf("%d %d", &n, &k) != EOF){
        for(i=0; i<n; i++){
            scanf("%d", &weight[i]);
            dp[0][i] = 0;
        }

        qsort(weight, n, sizeof(int), cmp);

        for(i=1; i<=k; i++){
            dp[i][2*i-1] = dp[i-1][2*i-3>=0?2*i-3:0]+pow(weight[2*i-1]-weight[2*i-2], 2);
            for(j=2*i; j<n; j++){
                tmp = dp[i-1][j-2]+pow(weight[j]-weight[j-1], 2);
               if(tmp < dp[i][j-1]){
                   dp[i][j] = tmp;
               }else{
                   dp[i][j] = dp[i][j-1];
               }
            }
        }
        printf("%d\n", dp[k][n-1]);
    }
    return 0;
}
