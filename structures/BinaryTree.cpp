#include <stdio.h>
#include <queue>

using namespace std;

struct Node{
  int nvalue;
  Node* pleft;
  Node* pright;
};

Node* reconstruct(int* preorder, int* inorder, int length){
  Node* root = new Node();
  root->nvalue = preorder[0];
  root->pleft = root->pright = NULL;
  int blen=0;
  while(blen<length && inorder[blen]!=preorder[0]){
    blen ++;
  }
  if(blen==length){
    printf("invalid input\n");
    return NULL;
  }
  if(blen>0){
    root->pleft = reconstruct(preorder+1, inorder, blen);
  }
  if(length-blen-1>0){
    root->pright = reconstruct(preorder+blen+1, inorder+blen+1, length-blen-1);
  }
  return root;
}

Node* reconstruct2(int* inorder, int* postorder, int length){
  Node* root = new Node();
  root->nvalue = postorder[length-1];
  root->pleft = root->pright = NULL;

  int blen = length-1;
  while(blen>=0 && inorder[blen]!=root->nvalue)
    blen --;
  if(blen>0)
    root->pleft = reconstruct2(inorder, postorder, blen);
  if(length-blen-1>0)
    root->pright = reconstruct2(inorder+blen+1, postorder+blen, length-blen-1);
  return root;
}

Node* construct(int *preorder, int* inorder, int length){
  if(preorder==NULL || inorder==NULL || length<=0)
    return NULL;
  return reconstruct(preorder, inorder, length);
}
Node* construct2(int* inorder, int *postorder, int length){
  if(inorder==NULL || postorder==NULL || length<=0)
    return NULL;
  return reconstruct2(inorder, postorder, length);
}

void preTraverse(Node* root){
  if(root!=NULL){
    printf("%d ", root->nvalue);
    preTraverse(root->pleft);
    preTraverse(root->pright); }
}

void inTraverse(Node* root){
  if(root!=NULL){
    inTraverse(root->pleft);
    printf("%d ", root->nvalue);
    inTraverse(root->pright);
  }
}

void postTraverse(Node* root){
  if(root!=NULL){
    postTraverse(root->pleft);
    postTraverse(root->pright);
    printf("%d ", root->nvalue);
  }
}
/*
void CengciTraverse(Node* root){
  queue<Node *> nq;
  Node* cur;
  nq.push(root);
  if(!nq.empty()){
    cur = nq.pop();
    printf("%d ", cur->nvalue);
    if(cur->pleft!=NULL)
      nq.push(cur->pleft);
    if(cur->pright!=NULL)
      nq.push(cur->pright);
  }
}
*/
void traverse(Node* root){
  printf("\npre-order:");
  preTraverse(root);
  printf("\nin-order:");
  inTraverse(root);
  printf("\npost-order:");
  postTraverse(root);
  //printf("\n曾测遍历:");
  //CengciTraverse(root);
}

void mirrorTree(Node* root){
  if(root==NULL)
    return;
  Node* tmp = root->pleft;
  root->pleft = root->pright;
  root->pright = tmp;
  mirrorTree(root->pright);
  mirrorTree(root->pleft);
}

int main(){
  //不能有重复输入
  int pre[]={1, 2, 4, 7, 3, 5, 6, 8};
  int in[]={4, 7, 2, 1, 5, 3, 8, 6};
  int post[]={7, 4, 2, 5, 8, 6, 3, 1};
  Node* root1 = construct(pre, in, 8);
  Node* root2 = construct2(in, post, 8);
  mirrorTree(root2);
  traverse(root1);
  traverse(root2);
  return 0;
}
