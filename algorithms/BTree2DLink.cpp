/**
 * Binary Tree To Double Link
 */
#include<stdio.h>
#include<stdlib.h>

struct Node {
  int val;
  Node *left;
  Node *right;
};

typedef struct Node *Tree;
typedef struct Node *DLink;

void convertNode(Tree root, DLink link){
  if(root==NULL)
    return ;
  if(root->left)
    convertNode(root->left, link);
  if(link==NULL)
    link = root;
  else{
    link->right = root;
    root->left = link;
    link = link->right;
  }
  if(root->right)
    convertNode(root->right, link);
}

Tree convertNode2(Tree root){
  if(root == NULL)
    return NULL;

  Tree left = convertNode2(root->left);
  root->left = left;
  if(left!=NULL)
    left->right = root;

  Tree right = convertNode2(root->right);
  root->right = right;
  if(right!=NULL){
    right->left = root;
    return right;
  }
  return root;
}

DLink convert(Tree root){
  DLink link=NULL;
  convertNode(root, link);
  //convertNode2(root);
  while(root!=NULL && root->left!=NULL)
    root = root->left;
  return root;
}

Tree insert(Tree root, int val){
  if(root == NULL){
    root = (Node *)malloc(sizeof(Node));
    root->val = val;
    root->left = root->right = NULL;
  }else if(val > root->val){
    root->right = insert(root->right, val);
  }else
    root->left = insert(root->left, val);

  return root;
}

void traverse(Tree root){
  if(root==NULL)
    return ;
  traverse(root->left);
  printf("%d ", root->val);
  traverse(root->right);
}

void loopLink(DLink link, int len){
  while(len--){
    printf("-%d ", link->val);
    link = link->right;
  }
}

int main(){
  Tree root = insert(NULL, 5);
  insert(root, 3);
  insert(root, 2);
  insert(root, 4);
  insert(root, 7);
  insert(root, 6);
  printf("tree is:\t");
  traverse(root);
  printf("\ndouble link is:\t");
  loopLink(root, 4);
}
