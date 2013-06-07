#include<stdio.h>
#include<stdlib.h>

#define MAX 101

//更好的方法是对end排序
int forjob(int *start,int *end,int n)
{
    int i, curHour = 1, maxHour=0, result;
    int *res = (int *)malloc(sizeof(int)*MAX);
    for(i=0; i<MAX; i++)
        res[i] = 0;
    while(curHour<MAX){
        for(i=0; i<n; i++){
            if(curHour == end[i]){
                if(res[curHour] < res[curHour-1])
                    res[curHour] = res[curHour-1];
                if(res[start[i]]+1>res[curHour])
                    res[curHour] = res[start[i]]+1;
            }else if(end[i]>maxHour)
                maxHour = end[i];
        }
        printf("\n %d:\t", curHour);
        for(i=0; i<=maxHour; i++)
          printf("%d ", res[i]);
        if(curHour>=maxHour)
            break;
        else
            curHour ++;
    }
    result = res[maxHour];
    free(res);
    return result;
}


int main()
{    
    int start[] = {9, 10, 7};
    int end[] = {10, 11, 12};
    printf("\n%d", forjob(start, end, 3));
}
