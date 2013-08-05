#include<stdio.h>

int StrToInt(const char* str)
{
    long long int val=0, max=1;
    int i=0, pos=1;
    while(str[i]==' ' || str[i]=='\t'){
        i++;
    }
    max = (max<<31)-1;
    if(str[i]=='-' || str[i]=='+'){
        if(str[i]=='-'){
            pos = -1;
            max ++;
        }
        i++;
    }    
    while(str[i]>='0' && str[i]<='9'){
        val = val*10 + str[i]-'0';
        if(val > max){
          val = max;
          break;
        }
        i++;
    }
    return val*pos;
}

int main(){
  printf("%d\n", StrToInt("2147483647"));
  printf("%d\n", StrToInt("2147483648"));
  printf("%d\n", StrToInt("-2147483648"));
  printf("%d\n", StrToInt("-2147483649"));
  printf("%d\n", StrToInt("-11919730356x"));
  printf("%d\n", StrToInt("+11191657170"));
  printf("%d\n", StrToInt("11810097701"));
}
