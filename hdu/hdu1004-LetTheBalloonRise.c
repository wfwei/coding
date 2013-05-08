#include<stdio.h>
#include<string.h>

typedef struct {
    char color[16];
    int count;
} Node;

int main(){
   int N=0;
   char color[16] = "";
   Node node[1010];
   while(scanf("%d", &N) != EOF && N > 0){
       int i=0, j=0, c=0, valmax=0, idxmax=0;
       for(i=0; i<N; i++){
          scanf("%s", color);
          for(j=0; j<c; j++){
              if(strcmp(color, node[j].color) == 0){
                  node[j].count += 1;
                  if(node[j].count > valmax){
                      valmax = node[j].count;
                      idxmax = j;
                  }
                  break;
              }
          }
          if(j == c){
              strcpy(node[j].color, color);
              node[j].count = 1;
              c++;
          }
       }
       printf("%s\n", node[idxmax].color);
   }
   return 0;
}
