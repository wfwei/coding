#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>

#define esp 1e-8
#define maxn 100020
#define zero(x) (((x)>0?(x):-(x)) < esp)

using namespace std;
struct point
{
    double x,y;
}p[maxn];
double dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp(const point &a,const point &b)
{
    if(fabs(a.x - b.x) < esp)
        return a.y < b.y;
    return a.x < b.x;
}
double solve(point p[],int n)
{
    double minvalue = 1e+10;
    if(n == 2)
    return dis(p[0],p[1]);
    for(int i = 0;i < n-2;++i)
        minvalue = min(minvalue,min(dis(p[i],p[i+1]),min(dis(p[i],p[i+2]),dis(p[i+1],p[i+2]))));
    return minvalue;
}
int main ()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i = 0;i < n;++i)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        double ans = solve(p,n);
        printf("%.2lf\n",ans/2);
    }
    return 0;
}
