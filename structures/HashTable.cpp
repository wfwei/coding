#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
  char* val;
  ListNode * next;
} * List;


typedef struct HashTb {
  int size;
  List list;
} HashTable;

int NextPrime(int n){
  int i;
  while(n++){
    for(i=(int)math.sqrt(n); i>1; i--){
      if(n%i == 0)
        return n;
    }
  }
}

void FatalError(char* msg){
  printf("%s", msg);
  exit(1);
}

int Hash(const char *key, int size){
  unsigned int val = 0;
  while(*key != '\0')
    val = (val<<5) ^ (*key++);
  return val%size;
}

HashTable InitTable(int size){

  HashTable h;
  int i;

  //check if size is Ok

  h = malloc(sizeof(HashTable));
  if(h==NULL)
    FatalError("No space left");
  h->size = NextPrime(size);
  h->list = malloc(sizeof(struct ListNode) * h->size);
  if(h->list == NULL){
    printf("out of space");
    exit(0);
  }
  
  for(i=0; i<h->size; i++){
    h->list[i] = malloc(sizeof(struct ListNode));
    if(h->list[i] == NULL)
      FatalError("No space left");
    else
      h->list[i]->next = NULL;
  }

  return h;
}

ListNode Find(char* val, HashTable h){

}

int main(){
  return 0;
}
