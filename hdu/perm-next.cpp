#include<stdio.h>
#include<string.h>
#include<algorithm>

#define MAX 100

using namespace std;

int cmp(const void *p, const void *q){
  return *(char *)p - *(char *)q;
}
 
int main()
{
    int len;
    char str[MAX];
    gets(str);
    len = strlen(str);
    qsort(str, len, sizeof(char), cmp);
    puts(str);
    while (next_permutation(str, str + len)){
        puts(str);
    }
    return 0;
}
