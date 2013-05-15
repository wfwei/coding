#include<stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_find(char  input[],   char rule[])
{
    int leni = strlen(input), lenr = strlen(rule);
    int i, j, ridx, lasti, found;
    char* res = (char *)malloc(sizeof(char)*(leni+1));
    memset(res, 0, sizeof(sizeof(char)*(leni+1)));

    for(i=0, j=0, ridx=0; i<leni;){
        if(rule[j] == '?'){
            j++;
            res[ridx++] = input[i++];
        } else if(rule[j] == '*'){
            while(rule[j]=='*' || rule[j]=='?')
              j++;
            if(j==lenr){
                while(i<leni){
                    res[ridx++] = input[i++];
                }
            }else{
                lasti = leni-1;
                found = 0;
                while(lasti>=i){
                  if(input[lasti]!=rule[j]){
                    lasti --;
                  }else{
                    char * subRes = my_find(input+lasti, rule+j);
                    if(strlen(subRes)>0){
                      found = 1;
                      while(i<lasti)
                        res[ridx++] = input[i++];
                      int k=0;
                      while(k<strlen(subRes)){
                        res[ridx++] = subRes[k++];
                        i++;
                      }
                      j=lenr;
                      //free(subRes);
                      break;
                    }else{
                      lasti --;
                      // free(subRes);
                    }
                  }
                }
                if(found==0){
                  i-=j-1;
                  j=0;
                }
            }
        } else {
            if(input[i]==rule[j]){
                res[ridx++] = input[i++];
                j++;
            }else{
                i-=j-1;
                j=0;
            }
        }
        if(j==lenr){
            res[ridx++] = ' ';
            j=0;
        }
    }
    while(ridx>=0 && res[ridx]!=' ')
        ridx --;
    res[ridx] = '\0';
    return res;
}



int main()
{    
    printf("aaa--aa--%s\n", my_find("aaa", "aa"));
    printf("ded--de--%s\n", my_find("ded", "de"));
    printf("abcc--a*c--%s\n", my_find("abcc", "a*c"));
    //printf("abcc--a*b--%s\n", my_find("abcc", "a*d"));
    printf("newsadfanewfdadsf--new--%s\n", my_find("newsadfanewfdadsf", "new"));
    printf("breakfastfood--f*d--%s\n", my_find("breakfastfood", "f*d"));
    printf("adfdededk--a*de--%s\n", my_find("adfdededk", "a*de"));
    return 0;
}
