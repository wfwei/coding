#include<stdio.h>
#include<stdlib.h>

#define MAXINT 1001

struct TP{
  int j, f;
  double val;
};

TP tp[MAXINT];

int cmp(const void *p, const void *q){
  return ((TP *)q)->val-((TP *)p)->val>0?1:-1; 
}

int main(){
  int m, n, i;
  double res;
  while(scanf("%d %d", &m, &n), m!=-1&&n!=-1){
    for(i=0; i<n; i++){
      scanf("%d %d", &tp[i].j, &tp[i].f);
      tp[i].val = 1.0 * tp[i].j / tp[i].f;
    }
    qsort(tp, n, sizeof(tp[0]), cmp);
    res = 0.0;
    for(i=0; i<n; i++){
      m-= tp[i].f;
      if(m<=0){
        res += 1.0*tp[i].j*(tp[i].f+m)/tp[i].f;
        break;
      }else{
        res += tp[i].j;
      }
    }    
    printf("%.3lf\n", res);
  }
}
