#include<stdio.h>
#include<math.h>

int main(){
   int T;
   double p1x, p1y, p2x, p2y, p3x, p3y, a, b, c, p, q, s;
   scanf("%d", &T);
   while(T--){
       scanf("%lf%lf%lf%lf%lf%lf", &p1x, &p1y, &p2x, &p2y, &p3x, &p3y);
       a = ((p1y-p2y)*(p1x-p3x)-(p1y-p3y)*(p1x-p2x))/((p1x*p1x-p2x*p2x)*(p1x-p3x)-(p1x*p1x-p3x*p3x)*(p1x-p2x));
       b=(p1y-p2y-a*(p1x*p1x-p2x*p2x))/(p1x-p2x);
       c=p1y-a*p1x*p1x-b*p1x;
       p=(p2y-p3y)/(p2x-p3x);
       q=p2y-p*p2x;
       s=a*p3x*p3x*p3x/3+(b-p)*p3x*p3x/2+(c-q)*p3x-(a*p2x*p2x*p2x/3+(b-p)*p2x*p2x/2+(c-q)*p2x);
       printf("%.2lf\n",s);
   }
}

