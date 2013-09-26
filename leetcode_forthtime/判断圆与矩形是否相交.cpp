#include<stdio.h>
#include<math.h>
int main()
{
    int m,n;
    double x,y,r,x1,y1,x2,y2;
    while(scanf("%d",&n)!=EOF&&n!=0)
    while(n--)
    {
      scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&r,&x1,&y1,&x2,&y2);
      if((x1-x)*(x1-x)+(y1-y)*(y1-y)<r*r&&(x2-x)*(x2-x)+(y1-y)*(y1-y)<r*r&&
      (x2-x)*(x2-x)+(y2-y)*(y2-y)<r*r&&(x1-x)*(x1-x)+(y2-y)*(y2-y)<r*r){printf("NO\n");continue;}
      if((x-x1)*(x-x2)<=0&&(fabs(y-y1)<=r||fabs(y-y2)<=r)){printf("YES\n");continue;}
      if((y-y1)*(y-y2)<=0&&(fabs(x-x1)<=r||fabs(x-x2)<=r)){printf("YES\n");continue;}
      if((x-x1)*(x-x1)+(y-y1)*(y-y1)<=r*r){printf("YES\n");continue;}
      if((x-x2)*(x-x2)+(y-y2)*(y-y2)<=r*r){printf("YES\n");continue;}
      if((x-x1)*(x-x1)+(y-y2)*(y-y2)<=r*r){printf("YES\n");continue;}
      if((x-x2)*(x-x2)+(y-y1)*(y-y1)<=r*r){printf("YES\n");continue;}
      printf("NO\n");
    }
    return 0;
}