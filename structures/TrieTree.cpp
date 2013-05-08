#include<stdio.h>

#define MAX 26

typedef struct Trie {
  Trie * next[MAX];
  int val; //次数
};

Trie *root;

void createTrie(char *str){
  int len = strlen(str), i, j;
  Trie *p=root, *q;
  for(i=0; i<len; i++){
    int id = str[i]-'0';
    if(p->next[id]==NULL){
      q = (Trie *)malloc(sizeof(Trie));
      q->val = 0;
      for(j=0; j<MAX; j++)
        q->next[j] = NULL;
      p->next[id] = q;
      p = q;
    } else {
      p->next[id]->v++;
      p = p->next[id];
    }
  } 
}

int findTrie(char *str){
  int len=strlen(str), i;
  Trie *p = root;
  if(p==NULL)
    return 0;
  for(i=0; i<len; i++){
    if(p->next[i]==NULL)
      return 0;
    else
      p = p->next[i];
  }
  return p->val;
}

int deleteTrie(Trie* T){
  int i;

  if(T==NULL)
    return 0;

  for(i=0; i<MAX; i++)
    if(T->next[i]!=NULL)
      deleteTrie(T->next[i]);

  delete(T);

  return 0;
}
