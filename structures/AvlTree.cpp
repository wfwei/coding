#include<stdio.h>
#include<stdlib.h>

#define Max(a, b) ((a)>(b)?(a):(b))

struct AvlNode {
  int val;
  AvlNode *left;
  AvlNode *right;
  int height;
};

typedef struct AvlNode* AvlTree;
typedef struct AvlNode* Node;

static int Height(AvlTree root){
  if(root==NULL)
    return -1;
  else
    return root->height;
}

void MakeEmpty(AvlTree root){
  if(root!=NULL){
    MakeEmpty(root->left);
    MakeEmpty(root->right);
    free(root);
  }
}

AvlTree SingleRotateWithLeft(AvlTree root){
  AvlTree newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;

  root->height=Max(Height(root->left), Height(root->right)) + 1;
  newRoot->height = Max(Height(newRoot->left), Height(newRoot->right))+1;

  return newRoot;
}

AvlTree SingleRotateWithRight(AvlTree root){
  AvlTree newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;

  root->height = Max(Height(root->left), Height(root->right))+1;
  newRoot->height = Max(Height(newRoot->left), Height(newRoot->right))+1;

  return newRoot;
}

AvlTree DoubleRotateWithLeft(AvlTree root){
  root->left = SingleRotateWithRight(root->left);
  return SingleRotateWithLeft(root);
}

AvlTree DoubleRotateWithRight(AvlTree root){
  root->right = SingleRotateWithLeft(root->right);
  return SingleRotateWithRight(root);
}

AvlTree Insert(int x, AvlTree root){
  if(root==NULL){
    root = (AvlNode *)malloc(sizeof(AvlNode));
    if(root == NULL){
      printf("Out of memory");
    }else{
      root->val = x;
      root->right = root->left = NULL;
    }
  } else if(x < root->val){
    root->left = Insert(x, root->left);
    if(Height(root->left)-Height(root->right) == 2){
      if(x<root->left->val)
        root = SingleRotateWithLeft(root);
      else
        root = DoubleRotateWithLeft(root);
    }
  } else if(x > root->val){
    root->right = Insert(x, root->right);
    if(Height(root->right)-Height(root->left) == 2){
      if(x>root->right->val)
        root = SingleRotateWithRight(root);
      else
        root = DoubleRotateWithRight(root);
    }
  }

  root->height = Max(Height(root->left), Height(root->right)) + 1;
  return root;
}

int main(){
// TODO
}
