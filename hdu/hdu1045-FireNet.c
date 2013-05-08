#include<stdio.h>

typedef struct {
    int val;
    int ava;
}Node;

int calc(int i, int j, int n, Node map[4][4]){
   int val=0;
   while(--i>=0){
        if(map[i][j].ava==1){
            val ++;
        }else{
            break;
        }
   }
   while(++i<n){
        if(map[i][j].ava==1){
            val ++;
        }else{
            break;
        }
   }

   while(--j>=0){
        if(map[i][j].ava==1){
            val ++;
        }else{
            break;
        }
   }
   while(++j<n){
        if(map[i][j].ava==1){
            val ++;
        }else{
            break;
        }
   }
   return val;
}

mark(int i, int j, int n, Node map[4][4]){
   while(--i>=0){
        if(map[i][j].ava==1){
            map[i][j].ava=0;
        }else{
            break;
        }
   }
   while(++i<n){
        if(map[i][j].ava==1){
            map[i][j].ava=0;
        }else{
            break;
        }
   }

   while(--j>=0){
        if(map[i][j].ava==1){
            map[i][j].ava=0;
        }else{
            break;
        }
   }
   while(++j<n){
        if(map[i][j].ava==1){
            map[i][j].ava=0;
        }else{
            break;
        }
   }
}


int main(){
    int i, j, n, min, id, jd, res, max=100;
    char c;
    Node map[4][4];

    while(scanf("%d", &n) && n>0){
        scanf("%c", &c);
        // init data
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%c", &c);
                if(c == '.'){
                    map[i][j].ava = 1;
                }else{
                    map[i][j].ava = 0;
                    map[i][j].val = max;
                }
            }
            scanf("%c",&c);
        }
        // greedy
        res = 0;
        while(1){

            // calc value 
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(map[i][j].ava == 1){
                        map[i][j].val = calc(i, j, n, map);
                    }
                    printf("%d\t", map[i][j].val);
                }
                printf("\n");
            }

           // find the min
           min = max;
           for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(map[i][j].ava==1 && map[i][j].val<min){
                   min = map[i][j].val;
                   id = i;
                   jd = j;
                }
            }
           }
           if(min == max){
               //over
               break;
           }else{
                res ++;
                mark(id, jd, n, map);
           }
        }
        printf("\n%d\n", res);
    }
    return 1;
}
