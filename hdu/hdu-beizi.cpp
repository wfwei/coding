/*
 * =====================================================================================
 *
 *       Filename:  hdu-beizi.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年03月29日 20时04分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  FengweiWang (@WeBless), cf.wfwei@gmail.com
 *   Organization:  workplex
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BZ{
	__int64 x1, y1, x2, y2, s, max1, max2;
	struct BZ *next;
};

BZ bzs[20001];

int cmp(const void *p, const void *q){
	BZ *pp = (BZ *)p;
	BZ *qq = (BZ *)q;
	return pp->max1>qq->max1? 1: 0;
}

int main(){
	int T, i, n, x, ti;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%I64d %I64d %I64d %I64d", &bzs[i].x1, &bzs[i].y1,&bzs[i].x2,&bzs[i].y2);
			bzs[i].s = (bzs[i].x2-bzs[i].x1)*(bzs[i].y2-bzs[i].y1);
			bzs[i].max1 = bzs[i].x1>bzs[i].y1?bzs[i].x1:bzs[i].y1;
			bzs[i].max2 = bzs[i].x2>bzs[i].y2?bzs[i].x2:bzs[i].y2;
		}
		qsort(bzs, n,sizeof(BZ), cmp);
		BZ head;
		head.next = &bzs[0];
		BZ *cur, *pre;
		for(i=0; i<n-1; i++){
			bzs[i].next = &bzs[i+1];
		}
		bzs[i].next = NULL;
		scanf("%d", &x);
		__int64 res=0; int lti=0;
		while(x--){
			scanf("%d", &ti);
			cur = head.next;
			pre = &head;
			while(cur!=NULL && cur->max1<ti){
				if(lti>cur->x1 && lti>cur->y1){
					res -= (lti-cur->x1)*(lti-cur->y1);
				}
				if(cur->max2<=ti){
					res+= cur->s;
					pre->next = cur->next;
					cur = cur->next;
				}else{
					res += (ti-cur->x1)*(ti-cur->y1);
					pre = cur;
					cur = cur->next;
				}
			}
			lti = ti;
			printf("%I64d\n", res);
		}
	}
}

