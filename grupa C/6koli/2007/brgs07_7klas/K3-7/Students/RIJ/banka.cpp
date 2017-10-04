#include<iostream>
using namespace std;
int nod(int a,int b)
{
    if (b>a) swap(a,b);
    int q;
    while(b)
    {
    q=a%b;
    a=b;
    b=q;
    }
    return a;
}
void f(int a,int b,int& x1,int& y1,int& x2,int& y2)
{
    int q,r,t;
    x1=1;x2=0;y1=0;y2=1;
    while(b)
    {
        q=a/b;
        r=a%b;
        a=b;b=r;
        t=x2;
        x2=x1-q*x2;
        x1=t;
        t=y2;
        y2=y1-q*y2;
        y1=t;
    }
}
int main()
{
    int n,s,min=2000000000,iz1,iz2=0,br1,br2;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    cin>>a[i];
    cin>>s;
    sort(a,a+n);
    for (int i=n-1;i>=0;i--)
    if (s%a[i]==0)
    if (s/a[i]<min)
    {
        iz1=a[i];
        br1=s/a[i];
        min=br1;
        break;
    }
    int b,x1,y1,x2,y2,m=2000000000,x,y;
    for (int i=n-1;i>0;i--)
    for (int j=i-1;j>=0;j--)
    {
        b=nod(a[i],a[j]);
        if (s%b) continue;
        f(a[i]/b,a[j]/b,x1,y1,x2,y2);
        x1=x1*(s/b);
        y1=y1*(s/b);
        if ((x1>m)||(y1>m)) continue;
        for(int k=-1;(x1+a[j]*k)>0;k--)
        if(y1-a[i]*k>0)
        {
            if((y1-a[i]*k+x1+a[j]*k)<min)
            {
            iz1=a[i];iz2=a[j];
            br1=x1+a[j]*k;br2=y1-a[i]*k;
            min=br1+br2; 
            }
            break;
        }
        m=x1;
        break;
    }   
    cout<<min<<endl<<iz1<<' '<<br1<<endl;
    if(iz2) cout<<iz2<<' '<<br2<<endl;
    return 0;
}

