/**
 * count reverse pairs using merging sorting idea
 */
#include<stdio.h>
#include<stdlib.h>

int rev(int *data, int s, int e, int *tmp){
  if(s>=e)
    return 0;
  else {
    int mid = s + (e-s)/2;
    int count = rev(data, s, mid, tmp) + rev(data, mid+1, s, tmp);
    int i, j, k;
    for(k=s, i=s, j=mid+1; i<=mid && j<=e;){
      if(data[i]<=data[j]){
        tmp[k] = data[i];
        i++, k++;
      }else{
        tmp[k] = data[j];
        j++, k++;
        count += (mid-i+1);
      }
    }
    while(i<=mid)
      tmp[k++] = data[i++];
    while(j<=e){
      tmp[k++] = data[j++];
    }
    for(i=s; i<=e; i++){
      data[i] = tmp[i];
    }
    return count;
  }
}

int countRevPairs(int *data, int len){
  if(data==NULL || len<0)
    return 0;

  int *copy = (int *)malloc(sizeof(int)*len);
  int *tmp = (int *)malloc(sizeof(int)*len);
  int i;
  for(i=0; i<len; i++)
    copy[i] = data[i];

  int count = rev(copy, 0, len-1, tmp);
  delete copy;
  delete tmp;

  return count;
}

int main(){
  int A[] = {2, 5, 1, 4};
  int count = countRevPairs(A, 4);
  printf("%d\n", count);
}
