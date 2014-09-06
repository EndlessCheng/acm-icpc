#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double pi = acos(-1.0);
double x,y,l,w,s,h;
double cal(double a)
{
    s = l*cos(a)+w*sin(a)-x;
    h = s*tan(a)+w*cos(a);
    return h;
}
int main()
{
    double left,right,mid,midmid;
    while(scanf("%lf%lf%lf%lf",&x,&y,&l,&w)!=EOF)
    {
        left = 0.0;
        right = pi/2;
        while(fabs(right-left)>1e-8)
        {
            mid = (left+right)/2;
            midmid = (mid+right)/2;
            if(cal(mid)>=cal(midmid))right = midmid;
            else left = mid;
        }
        if(cal(mid)<=y)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
