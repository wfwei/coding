#include<stdio.h>

typedef struct {
    int max;
    int sidx;
    int eidx;
} R;

int main(){
    int T, N, i, j, ipt;
    R res, tmp;
    scanf("%d", &T);
    for(j=0; j<T; j++){
        scanf("%d", &N);

        scanf("%d", &res.max);
        res.sidx = 0;
        res.eidx = 0;
        tmp = res;

        for(i=1; i<N; i++){
            scanf("%d", &ipt);
            if(tmp.max <= 0){
                tmp.max = ipt;
                tmp.sidx = i;
            }else{
                tmp.max += ipt;
            }
            tmp.eidx = i;
            if(tmp.max > res.max){
                res = tmp;
            }
        }

        printf("Case %d:\n", j+1);
        printf("%d %d %d\n", res.max, res.sidx+1, res.eidx+1);
        if(j < T-1){
            printf("\n");
        }
    }
    return 0;
}
