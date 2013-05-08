/* *
 * 快慢指针，用来:
 *  1. 查看链表是否有环
 *  2. 找链表中间位置的节点(比例节点)
 * */

#include<stdio.h>

struct Node {
  int val;
  struct Node *next;
};

typedef struct Node *Link;
typedef struct Node *Pointer;

bool hasCircle(Link link){
  Pointer pre, p;
  p = pre = link;
  while(p!=NULL){
    if(p->next!=pre){
      p=p->next;
      if(p==NULL)
        break;
      if(p->next!=pre){
        p=p->next;
        if(p==NULL)
          break;
      }else
        return 1;
    }else
      return 1;
    pre = pre->next;
  }
  return 0;
}

bool hasCircle2(Link link){
  Pointer pre, p;
  p = pre = link;
  while(true){
    if(p==NULL || p->next==NULL)
      return false;
    if(p->next==pre || p->next->next==pre)
      return true;
    p = p->next->next;
    pre = pre->next;
  }
}

//有环返回ＮＵＬＬ
Pointer findMid(Link link){
  Pointer fast, slow;
  fast = slow = link;
  while(true){
    if(fast!=NULL)
      fast = fast->next;
    if(fast!=NULL){
      if(fast==slow || fast->next==slow)
        return NULL;
      fast = fast->next;
      slow = slow->next;
    }
    if(fast==NULL)
      break;
  }
  return slow;
}
