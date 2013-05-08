#include<stdio.h>
#include<math.h>

typedef struct {
    int x;
    int y;
    int xmax;
    int xleft;
    int xright;
} Node;

Node calcPos(long N){
    Node n;
    n.y = (int)pow(N*1.0 - 1, 0.5) + 1;
    n.x = (int)(N - (n.y-1)*(n.y-1));
    n.xmax = 2*n.y -1;
    n.xleft = (n.x - 1) / 2;
    n.xright = (n.xmax - n.x) / 2;
    printf("\n%ld:n.x=%d,n.y=%d,n.xmax=%d,n.xleft=%d,n.xright=%d\n", N, n.x, n.y, n.xmax, n.xleft, n.xright);
    return n;
}
int main(){
    long N, M; 
    Node n, m;
    int len;
    while(scanf("%ld%ld", &N, &M) != EOF){
        if(N > M){
            N = N + M;
            M = N - M;
            N = N - M;
        }
        n = calcPos(N);
        m = calcPos(M);
        len = 0;
        if(n.y == m.y){
            len = m.x-n.x;
        }else if(m.xleft < n.xleft){
            len += 2*(m.y - n.y);
            len += 2*(n.xleft - m.xleft - 1);
            len += n.x % 2 == 1?1:0;
            len += m.x % 2 == 1?0:1;
            len ++;
        }else if(m.xright < n.xright){
            len += 2*(m.y - n.y);
            len += 2*(n.xright- m.xright - 1);
            len += n.x % 2 == 1?0:1;
            len += m.x % 2 == 0?0:1;
            len ++;
        }else{
            len += m.x % 2 == 1?1:0;
            len += n.x % 2 == 0?1:0;
            len += 2*(m.y - n.y - 1) + 1;
        }
        printf("%d\n", len);
    }
}
