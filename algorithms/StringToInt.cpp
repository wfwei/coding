#include<stdio.h>

// more smarter way to solve overflow problem
int StrToInt(const char* str)
{
    //int maxAbs=((unsigned int)~0)>>1,maxAbsDiv=maxAbs/10, maxAbsRem=maxAbs%10;
    int maxAbs=0x7FFFFFFF,maxAbsDiv=maxAbs/10, maxAbsRem=maxAbs%10;
    int val=0, i=0, sign=1;
    while(str[i]==' ')
        i++;
    if(str[i]=='-' || str[i]=='+'){
        if(str[i]=='-'){
            sign = -1;
            maxAbsRem ++;
        }
        i++;
    }    
    while(str[i]>='0' && str[i]<='9'){
        int d = str[i]-'0';
        if(val>maxAbsDiv || (val==maxAbsDiv && d>maxAbsRem)){
            val = maxAbs;
            break;
        }else{
            val = val*10 + str[i]-'0';
        }
        i++;
    }
    return sign>0?val:-val;
}

// use long to resolve overflow problem
int StrToInt1(const char* str)
{
    long long int val=0, max=1;
    int i=0, pos=1, sign=1;
    while(str[i]==' ' || str[i]=='\t'){
        i++;
    }
    max = (max<<31)-1;
    if(str[i]=='-' || str[i]=='+'){
        if(str[i]=='-'){
            sign = -1;
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
    return val*sign;
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
