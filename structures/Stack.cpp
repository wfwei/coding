#include<stdio.h>
#define SIZE 100

typedef struct {
  int top;
  int mintop;
  int items[SIZE];
  int minitems[SIZE];
} stack;

void init(stack s){
  s.top = -1;
  s.mint = -1;
}

bool isEmpty(stack s){
  if(s.top == -1)
    return 1;
  return 0;
}

bool isFull(stack s){
  if(s.top==SIZE-1)
    return 1;
  return 0;
}

void push(stack s, int val){
  printf("push value:%d", val);
  if(!isFull(s)){
    s.top ++;
    s.items[s.top] = val;
    if(s.mintop==-1 || s.minitems[s.mintop]>=val){
      s.mintop ++;
      s.minitems[s.mintop] = val;
    }
  }else
    printf("stack is full");
}

int pop(stack s){
  int val=-1;
  if(!isEmpty(s)){
    val = s.items[s.top];
    s.top --;
    if(val==s.minitems[s.mintop]){
      s.mintop--;
    }
  }else
    printf("stack is empty");
  return val;
}

int getMin(stack s){
  if(s.mintop>=0)
    return s.minitems[s.mintop];
  else
    printf("stack is empty");
  return -1;
}

int main(){
  stack s;
  init(s);
  push(s, 1);
  push(s, 2);
  push(s, 3);
  while(!isEmpty(s)){
    printf("%d ", pop(s));
  }
}
