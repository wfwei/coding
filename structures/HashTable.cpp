#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
  char* val;
  ListNode * next;
} * List;


typedef struct HashTb {
  int size;
  List * list;
} HashTable;

int NextPrime(int n){
  int i;
  while(n++){
    bool isPrime=true;
    for(i=(int)math.sqrt(n); i>1; i--){
      if(n%i == 0){
        isPrime=false;
        break;
      }
    }
    if(isPrime)
      return n;
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
  return val % size;
}

HashTable InitTable(int size){

  HashTable h;
  int i;

  //allocate memory
  h = malloc(sizeof(HashTable));
  if(h==NULL)
    FatalError("No space left");
  h->size = NextPrime(size);
  h->list = malloc(sizeof(struct ListNode) * h->size);
  if(h->list == NULL){
    printf("out of space");
    exit(0);
  }

  return h;
}

ListNode Find(char val, HashTable h){
  int hash = Hash(val, h->size); 
  ListNode * target = h->list[hash];
  while(target!=NULL && target->val!=val)
    target = target->next;
  return target;
}

ListNode Insert(char val, HashTable h){
  int hash;
  ListNode * node = Find(val, h);
  if(node == NULL){
    node = malloc(sizeof(ListNode));
    if(node==NULL)
      FatalError("No space left");
    hash = Hash(val, h->size);
    node->val = val;
    node->next = h->list[hash];
    h->list[hash] = node;
  }
  return node;
}

int main(){
  return 0;
}
