/*
TASK:trade
LANG:C++
*/
#include<iostream>
using namespace std;
double m,z,a[100001],sum;
long long n,x,y,i,used[100001],br1,br2,k;
char ch,c[100001];
int main()
{
    scanf("%ld",&n);
    scanf("%ld%ld%lf",&x,&y,&z);
    m=z;
    a[x]=0;
    c[x]='+';
    a[y]=2*z;
    c[y]='-';
    used[x]=used[y]=1;
    for(i=1;i<=n-1;i++)
    {
       scanf("%ld%ld%lf",&x,&y,&z);
       m=m+z;
       if (used[x]==1 && used[y]==1) {;}
       else
       {
          if (used[y]==1) {swap(x,y);}
          if (used[x]==1)
          {
             if (c[x]=='-')
             {
                c[y]='+';
             }
             if (c[x]=='+')
             {
                c[y]='-';
             }
             a[y]=2*z-a[x];
          }
       }
    }
    for(i=1;i<=n;i++)
    {
       sum=sum+a[i];
       if (c[i]=='+') {br1++;}
       else {br2++;}
    }
    if (br1>br2) {k=br1-br2;ch='+';}
    else {k=br2-br1;ch='-';}
    sum=sum-m;
    sum=sum/k;
    for(i=1;i<=n;i++)
    {  if (i!=n)
       {
          if (c[i]=='+')
          {
             printf("%.2lf ",a[i]+sum);       
          }
          else {printf("%.2lf ",a[i]-sum);}
       }
       else
       {
          if (c[i]=='+')
          {
             printf("%.2lf",a[i]+sum);       
          }
          else {printf("%.2lf",a[i]-sum);}
       }
    }
    cout<<endl;
    //system("pause");
    return 0; 
}
               

    






















