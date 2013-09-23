#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Node;

SearchTree MakeEmpty(SearchTree root){
  if(root!=NULL){
    MakeEmpty(root->left);
    MakeEmpty(root->right);
    free(root);
  }
  return NULL;
}

Node Find(int val, SearchTree root){
  if(root!=NULL){
    if(root->val == val)
      return root;
    if(root->val < val)
      return Find(val, root->right);
    else
      return Find(val, root->left);
  }else
    return NULL;
}

Node FindMin(SearchTree root){
  if(root!=NULL){
    if(root->left==NULL)
      return root;
    else
      return FindMin(root->left);
  }else
    return NULL;
}

Node FindMax(SearchTree root){
  if(root!=NULL){
    while(root->right!=NULL)
      root = root->right;
  }
  return root;
}

SearchTree Insert(int val, SearchTree root){
  if(root==NULL){
    root = (TreeNode *)malloc(sizeof(struct TreeNode));
    if(root == NULL)
      printf("Out of space!!!");
    else{
      root->val = val;
      root->left = root->right = NULL;
    }
  }else{
    if(val>root->val)
      root->right = Insert(val, root->right); 
    else if(val<root->val)
      root->left = Insert(val, root->left);
  }
  return root;
}

SearchTree Delete(int val, SearchTree root){
  if(root==NULL)
    printf("Element(%d) not found!!!", val);
  else{
    if(root->val>val)
      Delete(val, root->right);
    else if(root->val<val)
      Delete(val, root->left);
    else{
     if(root->left && root->right){
       Node tmp = findMin(root->right);
       root->val = tmp->val;
       Delete(root->val, root->right);
     }else{
       Node tmp = root;
       if(tmp->left!=NULL)
         root = tmp->left;
       else
         root = tmp->right;
       free(tmp);
     }
    }
  }

}

int main(){

}
